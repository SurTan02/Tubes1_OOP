#include "../include/CraftingTable.hpp"

/**
 * uncomment ini untuk mengoutput dari crafting table
 */
// #define DEBUG
// #define DEBUG_MIRROR

CraftingTable::CraftingTable() : Container(9) {}

string CraftingTable::getName(int n) {
	if (this->Content[n].item != nullptr) {
		return this->getItem(n).item->getName();
	} else {
		return NULL_ITEM;
	}
}

string CraftingTable::getType(int n) {
	if (this->Content[n].item != nullptr) {
		if (this->getItem(n).item->getTypeToString() == "TOOL") {
			return this->getItem(n).item->getName();
		} else {
			return this->getItem(n).item->getTypeToString();
		}
	} else {
		return NULL_ITEM;
	}
}


bool CraftingTable::isEmpty() {
	bool flag = true;

	for (int i = 0; i < this->getSize(); i++) {
		if (this->Content[i].item != nullptr) {
			flag = false;
		}
	}
	return flag;
}

bool CraftingTable::isTool() {
	bool flag = true;
	
	for (int i = 0; i < this->getSize(); i++) {
		if (this->Content[i].item != nullptr && this->getItem(i).item->getTypeToString() != "TOOL") {
			flag = false;
		}
	}
	return flag;
}

bool CraftingTable::isNonTool() {
	bool flag = true;

	for (int i = 0; i < this->getSize(); i++) {
		if (this->getItem(i).item->getTypeToString() == "TOOL") {
			flag = false;
		}
	}
	return flag;
}

bool CraftingTable::check(string* recipe) {
	bool flag = true;
	for (int i = 0; i < 9; i++) {
		if (!(this->getName(i) == recipe[i] || this->getType(i) == recipe[i])) {
			flag = false;
		}
	}

	return flag;
}


bool CraftingTable::checkMirror(string* recipe) {
	bool flag = true;
	int i = 2;
	for (int j = 0; j < 9; j++) {
		if (!(this->getName(j) == recipe[i] || this->getType(j) == recipe[i])) {    // jika ada yang tidak sama dengan mirror recipe
			flag = false;
		}

		if (i % 3 == 0) {i += 5;}
		else            {i--;}
	}

	return flag;
}

bool CraftingTable::checkSub(string* recipe, int row, int column) {
	if (!(row == 3 && column == 3)) {
		string* temp = new string[9];

		for (int i = 0; i < 9; i++) {
			temp[i] = recipe[i];
		}
		int n = 9 - ((row - 1) * 3 + (column - 1));
		for (int i = 0; i < n; i++) {
			if (this->check(temp) || this->checkMirror(temp)) {
				delete[] temp;
				return true;
			}

			for (int j = 8; j > 0; j--) {
				temp[j] = temp[j - 1];
			}
			temp[0] = NULL_ITEM;
		}
		delete[] temp;
		return false;
	} else {
		return false;
	}
}



//Tambah parameter inventory
//Jadi void
// void CraftingTable::craft(std::vector<Recipe> recipes, Container Inventory) {
void CraftingTable::craft(Container& Inventory) {
	if (this->isEmpty()) {
		throw FailedCraftException();
	} else {
		if (this->isTool()) {       // if it's a Tool
			int count = 0;
			string item_name;
			int durability;
			for (int i = 0; i < this->getSize(); i++) {
				if (this->Content[i].item != nullptr) {
					if (count == 0) {
						item_name = this->getName(i);
						durability = ((Tool*) this->getItem(i).item)->getDurability();
						count++;
					} else if (count == 1) {
						if (item_name == this->getName(i)) {
							durability += ((Tool*) this->getItem(i).item)->getDurability();
							count++;
						} else {
							throw FailedCraftException();
							return;
						}
					} else { 
						throw FailedCraftException();
						return;
					}
				}
			}

			// string ids, type, typeTool;
			int id = getIDfromName(item_name);
			string typeTool = getTypefromName(item_name);

			try{
				Inventory.insert(*listItem[id-1], std::min(durability, 10));

				for (int i = 0; i < this->getSize(); i++) {
					if (this->Content[i].item != nullptr) {
						this->discard(i, 1);
					}
				}
			} catch (Exception &e){
				throw ;
			}
			return;
		} else {                        // if it's a NonTool
			std::vector<Recipe*>::iterator ptr = recipes.begin();
			bool flag = false;
			string item_name;

			while (ptr < recipes.end() && !flag) {
				if (this->check((*ptr)->getBlueprint()) || this->checkMirror((*ptr)->getBlueprint()) || (this->checkSub((*ptr)->getBlueprint(), (*ptr)->getRow(), (*ptr)->getColumn()))) {
					flag = true;
					item_name = (*ptr)->getItemName();
				}
				else ptr++;
			}
			if (flag) {
				/* Hitung QTY */
				int qty = 65; /* karena qty max 64 */

				for (int i = 0; i < 9; i++) {
					if (this->getItem(i).qty < qty) {
						qty = this->getItem(i).qty;
					}
				}
				
				/* TO DO: Check Tool atau NonTool */
				int id = getIDfromName(item_name);
				string typeTool = getTypefromName(item_name);

				if (typeTool == "TOOL") {
					try{
						for (int i = 0; i < qty; i++) {
							Inventory.insert(*listItem[id-1], 10);
							for (int i = 0; i < this->getSize(); i++) {
								if (this->Content[i].item != nullptr) {
									this->discard(i, 1);
								}
							}
						}
					} catch (Exception &e){
						throw ;
					}
					return;
				} else {
					try{
						for (int i = 0; i < qty; i++) {
							Inventory.insert((*ptr)->getCreatedProduct(), *listItem[id-1]);
							for (int i = 0; i < this->getSize(); i++) {
								if (this->Content[i].item != nullptr) {
									this->discard(i, 1);
								}
							}
						}
					} catch (Exception &e){
						throw ;
					}
					return;
				}
			} else {
				throw FailedCraftException();
				return;
			}
			
		}
	}
}

