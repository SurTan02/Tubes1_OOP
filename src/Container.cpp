#include "../include/Container.hpp"
#define NULL_ITEM "NULLITEM"

Container::Container(int size) {
    this->size = size;
    this->Content = new Slot[size];
    for (int i = 0; i < this->size; i++) {
        Content[i].item = &listItem[0];
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
    int FirstNull;
    if (itemX.getType() != ItemType::Tool) {
        for (int i = 0; i < 27; i++) {
            if (Content[i].item->getName() == itemX.getName()) {
                int temp = Content[i].qty + n;
                if (temp > 0) insert(temp,itemX);
                break;
            }
            if (Content[i].item->getName() == NULL_ITEM && !flagNull) {
                FirstNull = i;
                flagNull = true;
            }
        }
        Content[FirstNull].item = &itemX;
        Content[FirstNull].qty = 1;
    }
    else {
        for (int i = 0; i < 27; i++) {
            if (Content[i].item->getName() == NULL_ITEM) {
                Content[i].item = &itemX;
                break;
            }
        }
    }
}    

void Container::discard(int index, int n) {
    if (Content[index].item->getType() == ItemType::Tool) {
        Content[index].item = &listItem[0];
        Content[index].qty = 0;
        // for (int i=0; i<27; i++) {
        //     if (Content[i].item->getName() == itemX.getName()){
        //         Content[i].item = new Tool(0, NULL_ITEM, 0);
        //         break;
        //     }
        // }
    }
    else {
        if (Content[index].qty < n) {
            Content[index].item = &listItem[0];
            Content[index].qty = 0;
        } else {
            Content[index].qty -= n;
        }
        
    }
}