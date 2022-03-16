#include "../include/Inventory.hpp"
#define NULL_ITEM "NULLITEM"

Inventory::Inventory(){
    
    this->size = 27;
    for (int i=0; i<this->size; i++){
        
            Content[i] = new Tool(0, NULL_ITEM, 0);
        
    }
}

Inventory::~Inventory(){
    // delete [] Content;
}

int Inventory::getSize(){
    return this->size;
}

Item* Inventory::getItem(int index){
    if (Content[index]->getType() == ItemType::Tool)
        return Content[index];
    else
        return (Content[index]);   
}

void Inventory::insert(int n, Item& itemX){
    bool flagNull = false;
    int FirstNull;
    if (itemX.getType() != ItemType::Tool){
        for (int i=0; i<27; i++){
            if (Content[i]->getName() == itemX.getName()){
                //int temp = Content[i].addQuantity(n);
                // if (temp > 0) insert(temp,itemX);
                // break
            }
            if (Content[i]->getName() == NULL_ITEM && !flagNull){
                FirstNull = i;
                flagNull = true;
            }
        }
        Content[FirstNull] = &itemX;;
    }
    else{
        for (int i=0; i<27; i++){
            if (Content[i]->getName() == NULL_ITEM){
                Content[i] = &itemX;
                break;
            }
        }
    }
    
}
void Inventory::discard(int index, int n, Item& itemX){
    if (itemX.getType() == ItemType::Tool){
        for (int i=0; i<27; i++){
            if (Content[i]->getName() == itemX.getName()){
                Content[i] = new Tool(0, NULL_ITEM, 0);
                break;
            }
        }
    }
    else{
        for (int i=0; i<27; i++){
            if (Content[i]->getName() == itemX.getName()){
                // Content[i].RemoveQuantity(n);
                // if (Content[i].getQuantity() == 0) Content[i] = new Tool(0, NULL_ITEM, 0);
                //break;
            }
        }
    }
}