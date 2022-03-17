#include "../include/Container.hpp"
#define NULL_ITEM "NULLITEM"

Container::Container(int size) {
    this->size = size;
    this->Content = new Slot[size];
    for (int i = 0; i < this->size; i++) {
        // Content[i].item = &listItem[0];
        Content[i].item = new Tool(0, NULL_ITEM, 0);
        
        Content[i].qty = 0;
    }
}

Container::~Container() {
    delete[] Content;
}

Slot Container::getItem(int index) {
    return Content[index];
}

int Container::getSize() {
    return this->size;
}

void Container::insert(int n, Item& itemX) {
    bool flagNull = false;
    bool found = false;
    int FirstNull;
    int i = 0;
    if (itemX.getType() != ItemType::Tool) {
        
        while (i < 27 && !found) {
            if (Content[i].item->getName() == itemX.getName() && Content[i].qty < 64) {
                int temp = Content[i].qty + n;
                if (temp > 64){
                    Content[i].qty = 64;
                    insert(temp-64,itemX);
                }
                else Content[i].qty = temp;
                
                found = true;
            }
            else if (Content[i].item->getName() == NULL_ITEM && !flagNull) {
                FirstNull = i;
                flagNull = true;
            }
            i++;
        }
        if (flagNull && !found){
            Content[FirstNull].item = &itemX;
            Content[FirstNull].qty = n;
        }
        
    }
    else {
        for (int i = 0; i < 27; i++) {
            if (Content[i].item->getName() == NULL_ITEM) {
                Content[i].item = &itemX;
                Content[i].qty = 1;
                break;
            }
        }
    }
}    

void Container::discard(int index, int n) {
    if (Content[index].item->getType() == ItemType::Tool) {
        // Content[index].item = &listItem[0];
        Content[index].item = new Tool(0, NULL_ITEM, 0);
        Content[index].qty = 0;
        // for (int i=0; i<27; i++) {
        //     if (Content[i].item->getName() == itemX.getName()){
        //         Content[i].item = new Tool(0, NULL_ITEM, 0);
        //         break;
        //     }
        // }
    }
    else {
        if (Content[index].qty <= n) {
            // Content[index].item = &listItem[0];
            Content[index].item = new Tool(0, NULL_ITEM, 0);
            Content[index].qty = 0;
        } else {
            Content[index].qty -= n;
        }
        
    }
}