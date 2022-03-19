#include "../include/CraftingTable.hpp"

CraftingTable::CraftingTable() : Container(9) {}

string CraftingTable::getName(int n) {
    if (this->getItem(n).item->getTypeToString() == "Plank") {
        return this->getItem(n).item->getTypeToString();
    } else {
        return this->getItem(n).item->getName();
    }
}

bool CraftingTable::isEmpty() {
    bool flag = true;

    for (int i = 0; i < this->getSize(); i++) {
        if (this->getName(i) != NULL_ITEM) {
            flag = false;
        }
    }
    return flag;
}

bool CraftingTable::isTool() {
    bool flag = true;

    for (int i = 0; i < this->getSize(); i++) {
        if (this->getItem(i).item->getTypeToString() != "Tool" || this->getName(i) != NULL_ITEM) {
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

bool CraftingTable::check(vector<string> recipe) {
    std::vector<string>::iterator ptr;
    bool flag = true;
    int i = 0;
    for (ptr = recipe.begin(); ptr < recipe.end(); ptr++) {
        if (this->getName(i) != *ptr) {
            flag = false;
        }

        i++;
    }
    return flag;
}

bool CraftingTable::checkMirror(std::vector<string> recipe) {
    std::vector<string>::iterator ptr;
    bool flag = true;
    int i = 2;
    for (ptr = recipe.begin(); ptr < recipe.end(); ptr++) {
        if (this->getName(i) != *ptr) {
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

bool CraftingTable::checkSub(std::vector<string> recipe, int row, int column) {
    if (row != 3 && column != 3) {
        std::vector<string> temp = recipe;
        int n = 9 - ((row - 1) * 3 + (column - 1)) - 1;
        for (int i = 0; i < n; i++) {
            if (this->check(temp) || this->checkMirror(temp)) {
                return true;
            }
            temp.pop_back();
            temp.insert(temp.begin(), NULL_ITEM);
        }
        return false;
    } else {
        return false;
    }
}


//Tambah parameter inventory
//Jadi void
Item* CraftingTable::craft(std::vector<Recipe> recipes, Container Inventory) {
    if (this->isEmpty()) {
        throw "nda bisa di craft gan";
    } else {
        if (this->isTool()) {
            int count = 0;
            string item_name;
            int durability;                                                                 //TODO BATAS ATAS DURABILITY = 10
            for (int i = 0; i < this->getSize(); i++) {
                if (this->getName(i) != NULL_ITEM) {
                    if (count == 0) {
                        item_name = this->getName(i);
                        durability = ((Tool*) this->getItem(i).item)->getDurability();
                        count++;
                    } else if (count == 1) {
                        if (item_name == this->getName(i)) {
                            durability += ((Tool*) this->getItem(i).item)->getDurability();
                            count++;
                        } else {
                            throw "nda bisa di craft gan";
                        }
                    } else {
                        throw "nda bisa di craft gan";
                    }
                }
            }
            
            try{
                // Nama Item Dihasilkan
                // listItem[i]->getname == NamaItemDIhasilkan
                // Inventory.insert(*listItem[idx], durability)

                for (int i = 0; i < this->getSize(); i++) {
                    if (this->getName(i) != NULL_ITEM) {
                        this->discard(i, 1);
                    }
                }
            } catch (Exception &e){
                throw(e);
            }

            /* TO DO: ID */
            //Gaperlu
            return new Tool(1, item_name, durability);

        } else {
            std::vector<Recipe>::iterator ptr;
            for (ptr = recipes.begin(); ptr < recipes.end(); ptr++) {
                bool flag = this->check(ptr->getBlueprint()) || this->checkMirror(ptr->getBlueprint()) || (this->checkSub(ptr->getBlueprint(), ptr->getRow(), ptr->getColumn()));
                if (flag) {
                    for (int i = 0; i < this->getSize(); i++) {
                        if (this->getName(i) != NULL_ITEM) {
                            this->discard(i, 1);
                            
                        }
                    }
                    /* TO DO: Check Tool atau NonTool */
                    string ids, type, typeTool;
                    int id = 0;
                    stringstream words(getIDandTypefromName(ptr->getItemName()));
		            words >> id >> type >> typeTool;
                    stringstream ss(ids);
                    ss >> id;
                    if (typeTool == "NONTOOL") {
                        //Sama dengan atas
                        //Inventory.insert(quantity,*listItem[idx])
                        //Try Catch
                        //Gaperlu return
                        return new NonTool(id, ptr->getItemName(), getItemType(type));
                    } else {
                        //Sama dengan atas
                        // Inventory.insert(*listItem[idx], 10)
                        //Try Catch
                        //Gaperlu return
                        return new Tool(id, ptr->getItemName(), 10);
                    }
                } else {
                    throw "nda bisa di craft gan";
                }
            }
        }
    }
}

