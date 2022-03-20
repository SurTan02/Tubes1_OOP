#include "../include/CraftingTable.hpp"

CraftingTable::CraftingTable() : Container(9) {}

string CraftingTable::getName(int n) {
    if (this->Content[n].item != nullptr) {
        if (this->getItem(n).item->getTypeToString() == "Plank") {
            return this->getItem(n).item->getTypeToString();
        } else {
            return this->getItem(n).item->getName();
        }
    } else {
        throw EmptySourceException();
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
        if (this->getItem(i).item->getTypeToString() != "Tool" || this->Content[i].item != nullptr) {
            flag = false;
        }
    }
    return flag;
}

bool CraftingTable::isNonTool() {
    bool flag = true;

    for (int i = 0; i < this->getSize(); i++) {
        if (this->getItem(i).item->getTypeToString() == "Tool") {
            flag = false;
        }
    }
    return flag;
}

bool CraftingTable::check(string* recipe) {
    bool flag = true;
    
    for (int i = 0; i < 9; i++) {
        if (this->getName(i) != recipe[i]) {
            flag = false;
        }

        i++;
    }
    return flag;
}

bool CraftingTable::checkMirror(string* recipe) {
    std::vector<string>::iterator ptr;
    bool flag = true;
    int i = 2;
    for (int j = 0; j < 9; j++) {
        if (this->getName(i) != recipe[j]) {
            flag = false;
        }

        if (i % 3 == 0) {
            i += 5;
        } else {
            i--;
        }
    }
    return flag;
}

bool CraftingTable::checkSub(string* recipe, int row, int column) {
    if (row != 3 && column != 3) {
        string* temp = new string[9];

        for (int i = 0; i < 9; i++) {
            temp[i] = recipe[i];
        }

        int n = 9 - ((row - 1) * 3 + (column - 1)) - 1;
        for (int i = 0; i < n; i++) {
            if (this->check(temp) || this->checkMirror(temp)) {
                return true;
            }

            for (int j = 1; j < 9; j++) {
                temp[j] = temp[j - 1];
            }

            temp[0] = NULL_ITEM;
        }
        return false;
    } else {
        return false;
    }
}


//Tambah parameter inventory
//Jadi void
// void CraftingTable::craft(std::vector<Recipe> recipes, Container Inventory) {
void CraftingTable::craft(Container Inventory) {
    if (this->isEmpty()) {
        throw FailedCraftException();
        
    } else {
        if (this->isTool()) {
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

            string ids, type, typeTool;

            stringstream words(getIDandTypefromName(item_name));
            words >> ids >> type >> typeTool;

            int id;
            stringstream ss(ids);
            ss >> id;
            
            try{
                Inventory.insert(std::max(durability, 10), *listItem[id]);

                for (int i = 0; i < this->getSize(); i++) {
                    if (this->Content[i].item != nullptr) {
                        this->discard(i, 1);
                    }
                }
            } catch (Exception &e){
                throw &e;
            }
            return;
        } else {
            std::vector<Recipe*>::iterator ptr;
            for (ptr = recipes.begin(); ptr < recipes.end(); ptr++) {
                bool flag = this->check((*ptr)->getBlueprint()) || this->checkMirror((*ptr)->getBlueprint()) || (this->checkSub((*ptr)->getBlueprint(), (*ptr)->getRow(), (*ptr)->getColumn()));
                if (flag) {
                    for (int i = 0; i < this->getSize(); i++) {
                        if (this->Content[i].item != nullptr) {
                            this->discard(i, 1);
                            
                        }
                    }
                    /* TO DO: Check Tool atau NonTool */
                    string ids, type, typeTool;
                    stringstream words(getIDandTypefromName((*ptr)->getItemName()));
		            words >> ids >> type >> typeTool;

                    int id;
                    stringstream ss(ids);
                    ss >> id;

                    if (typeTool == "NONTOOL") {
                        try{
                            Inventory.insert(10, *listItem[id]);

                            for (int i = 0; i < this->getSize(); i++) {
                                if (this->Content[i].item != nullptr) {
                                    this->discard(i, 1);
                                }
                            }
                        } catch (Exception &e){
                            throw &e;
                        }
                        return;
                    } else {
                        try{
                            Inventory.insert((*ptr)->getCreatedProduct(), *listItem[id]);

                            for (int i = 0; i < this->getSize(); i++) {
                                if (this->Content[i].item != nullptr) {
                                    this->discard(i, 1);
                                }
                            }
                        } catch (Exception &e){
                            throw &e;
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
}

