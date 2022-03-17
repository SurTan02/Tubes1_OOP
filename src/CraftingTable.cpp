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

Item* CraftingTable::craft(std::vector<Recipe> recipes) {
    if (this->isEmpty()) {
        throw "nda bisa di craft gan";
    } else {
        if (this->isTool()) {
            int count = 0;
            string item_name;
            int durability;
            for (int i = 0; i < this->getSize(); i++) {
                if (this->getName(i) != NULL_ITEM) {
                    if (count == 0) {
                        item_name = this->getName(i);
                        durability = ((Tool*) this->getItem(0).item)->getDurability();
                        count++;
                    } else if (count == 1) {
                        if (item_name == this->getName(i)) {
                            durability += ((Tool*) this->getItem(0).item)->getDurability();
                            count++;
                        } else {
                            throw "nda bisa di craft gan";
                        }
                    } else {
                        throw "nda bisa di craft gan";
                    }
                }
            }
            /* TO DO: destruct semua item - DONE */
            for (int i = 0; i < this->getSize(); i++) {
                if (this->getName(i) != NULL_ITEM) {
                    delete this->Content->item; /* gini kah (?) ga yakin */
                }
            }
            /* TO DO: ID */
            return new Tool(1, item_name, durability);
        } else {
            std::vector<Recipe>::iterator ptr;
            for (ptr = recipes.begin(); ptr < recipes.end(); ptr++) {
                std::vector<string>::iterator pt;
                bool flag = true;
                int i = 0;
                for (pt = ptr->getBlueprint().begin(); pt < ptr->getBlueprint().end(); pt++) {
                    /* To Do: MIRROR */

                    /* To Do: Sub Array */
                    if (this->getName(i) != *pt) {
                        flag = false;
                    }
                    i++;
                }
                if (flag) {
                    for (int i = 0; i < this->getSize(); i++) {
                        if (this->getName(i) != NULL_ITEM) {
                            delete this->Content->item; /* gini kah (?) ga yakin */
                        }
                    }
                    /* TO DO: Check Tool atau NonTool */
                    return new Tool(1, item_name, durability);
                }
            }
        }
    }
}
