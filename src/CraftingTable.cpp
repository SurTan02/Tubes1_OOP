#include "../include/CraftingTable.hpp"

/**
 * uncomment ini untuk mengoutput dari crafting table
 */
#define DEBUG

CraftingTable::CraftingTable() : Container(9) {}

string CraftingTable::getName(int n) {
    if (this->Content[n].item != nullptr) {
        if (this->getItem(n).item->getTypeToString() == "Plank") {
            return this->getItem(n).item->getTypeToString();
        } else {
            return this->getItem(n).item->getName();
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
        if (this->Content[i].item != nullptr && this->getItem(i).item->getTypeToString() != "Tool") {
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
        #ifdef DEBUG
        cout<< this->getName(i) <<" == "<< recipe[i]<<endl;
        #endif
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
    #ifdef DEBUG
    cout << "MASUK CHECK SUB" << endl;
    #endif
    if (row != 3 && column != 3) {
        string* temp = new string[9];

        for (int i = 0; i < 9; i++) {
            temp[i] = recipe[i];
        }

        #ifdef DEBUG
        cout << "Recipe" << endl;

        for (int i = 0; i < 9; i++) {
            cout << recipe[i] << " ";
        }
        
        cout << endl;
        #endif

        int n = 9 - ((row - 1) * 3 + (column - 1)) - 1;
        for (int i = 0; i < n; i++) {
            
            #ifdef DEBUG
            cout << "SUB" << endl;

            for (int i = 0; i < 9; i++) {
                cout << temp[i] << " ";
            }
            cout << endl;
            #endif

            if (this->check(temp) || this->checkMirror(temp)) {
                return true;
            }

            for (int j = 8; j > 0; j--) {
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
void CraftingTable::craft(Container& Inventory) {
    #ifdef DEBUG
    cout<<"TES Craft 1\n";
    #endif
    if (this->isEmpty()) {
        #ifdef DEBUG
        cout<<"TES CRAFT EMpty\n";
        #endif

        throw FailedCraftException();
    
    } else {
        #ifdef DEBUG
        cout<<"TES CRAFT Else\n";
        #endif

        if (this->isTool()) {
            int count = 0;
            string item_name;
            int durability;
            #ifdef DEBUG
            cout<<"TES CRAFT TOOL\n";
            #endif
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

            // stringstream words(getIDandTypefromName(item_name));
            // words >> ids >> type >> typeTool;
            //  int id;
            // stringstream ss(ids);
            // ss >> id;
            

            int id = getIDfromName(item_name);
            string typeTool = getTypefromName(item_name);

           
            try{
                Inventory.insert(*listItem[id-1], std::max(durability, 10));

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
            std::vector<Recipe*>::iterator ptr = recipes.begin();
            #ifdef DEBUG
            cout<<"TES CRAFT NonTool\n";
            #endif
            bool flag = false;
            string item_name;

            while (ptr < recipes.end() && !flag) {
                #ifdef DEBUG
                cout<< "RESEP SEKARANG " << (*ptr)->getItemName() << endl;
                #endif
                if (this->check((*ptr)->getBlueprint()) || this->checkMirror((*ptr)->getBlueprint()) || (this->checkSub((*ptr)->getBlueprint(), (*ptr)->getRow(), (*ptr)->getColumn()))) {
                    flag = true;
                    item_name = (*ptr)->getItemName();
                }
                else ptr++;
            }

            if (flag) {
                
                /* TO DO: Check Tool atau NonTool */
                #ifdef DEBUG
                cout<<"BISA\n";
                #endif
                // string ids, type, typeTool;
                // stringstream words(getIDandTypefromName((*ptr)->getItemName()));
                // words >> ids >> type >> typeTool;

                // int id;
                // stringstream ss(ids);
                // ss >> id;
                int id = getIDfromName(item_name);
                string typeTool = getTypefromName(item_name);

                #ifdef DEBUG
                cout<<"id "<<id;
                cout<<typeTool<<endl;
                #endif
                if (typeTool == "Tool") {
                    #ifdef DEBUG
                    cout<<"Hasil Tool\n";
                    #endif
                    try{
                        
                        Inventory.insert(*listItem[id-1], 10);
                        for (int i = 0; i < this->getSize(); i++) {
                            if (this->Content[i].item != nullptr) {
                                this->discard(i, 1);
                            }
                        }
                    } catch (Exception &e){
                        throw ;
                    }
                    return;
                } else {
                    #ifdef DEBUG
                    cout<<"Hasil NonTool\n";
                    // cout<<(*ptr)->getCreatedProduct();
                    
                    cout<<"nama "<<(listItem[id-1]->getName());
                    cout<<" nama "<<(*ptr)->getItemName();

                    
                    cout << "done til here" << endl;
                    #endif

                    try{
                        #ifdef DEBUG
                        cout<<"HASIL "<<(*ptr)->getCreatedProduct()<<endl;
                        cout<<(listItem[id-1]->getName());
                        #endif

                        Inventory.insert((*ptr)->getCreatedProduct(), *listItem[id-1]);

                        #ifdef DEBUG
                        cout<<"TES DISCARD";
                        #endif

                        for (int i = 0; i < this->getSize(); i++) {
                            if (this->Content[i].item != nullptr) {
                                this->discard(i, 1);
                            }
                        }

                        #ifdef DEBUG
                        cout<<"DONE";
                        #endif

                    } catch (Exception &e){
                        cout<<"THrow Nontool\n";
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

