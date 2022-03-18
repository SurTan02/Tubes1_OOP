#include "../include/Container.hpp"
#define NULL_ITEM "NULLITEM"
#include <iomanip>
Container::Container(int size) {
    this->size = size;
    this->Content = new Slot[size];
    for (int i = 0; i < this->size; i++) {
        // Content[i].item = null
        Content[i].item = nullptr;
        //Content[i].item = new Tool(0, NULL_ITEM, 0);
        
        Content[i].qty = 0;
    }
}

Container::~Container() {
    delete[] Content;
}

Container::Slot Container::getItem(int index) {
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
            if (Content[i].item == nullptr) {
                
                if (!flagNull){
                    flagNull = true;
                    FirstNull = i;
                }
            }
            else if (Content[i].item->getName() == itemX.getName() && Content[i].qty < 64) {
                int temp = Content[i].qty + n;
                if (temp > 64){
                    Content[i].qty = 64;
                    insert(temp-64,itemX);
                }
                else Content[i].qty = temp;
                
                found = true;
            }
            // else if (Content[i].item->getName() == NULL_ITEM && !flagNull) {
            //     FirstNull = i;
            //     flagNull = true;
            // }
            i++;
        }
        if (flagNull && !found){
            Content[FirstNull].item = &itemX;
            Content[FirstNull].qty = n;
        }
        
    }
    else {
        for (int i = 0; i < 27; i++) {
            if (Content[i].item == nullptr) {
                Content[i].item = &itemX;
                Content[i].qty = 1;
                break;
            }
        }
    }
}    

void Container::insert(int n, Item& itemX, int index){

    if (itemX.getType() != ItemType::Tool) {
        
            if (Content[index].item->getName() == itemX.getName() && Content[index].qty < 64) {
                int temp = Content[index].qty + n;
                if (temp > 64){
                    Content[index].qty = 64;
                    insert(temp-64,itemX);
                }
                else Content[index].qty = temp;
            }
            else if (Content[index].item->getName() == NULL_ITEM){
                Content[index].item = &itemX;
                if (n > 64){
                    Content[index].qty = 64;
                    insert(n-64,itemX);
                }
                else Content[index].qty = n;
            }
            else{
                throw ("Ada Item lain disini");                 //Perlu handle kalau dia udah ada item di Content[index] ?
                // throw (new Xerror); 
            }
        }
        
    else {
        // if (Content[index].item->getName() == NULL_ITEM){ 
        if (Content[index].item == nullptr){ 
                Content[index].item = &itemX;
                Content[index].qty = 1;
                
        }
        else{
            throw ("Ada Item Lain disini");                                 //Perlu handle kalau dia udah ada item di Content[index] ?
            // throw (new Xerror);
        }
        
    }
}

void Container::discard(int index, int n) {
    if (Content[index].item->getType() == ItemType::Tool) {
        Content[index].item = nullptr;
        Content[index].qty = 0;
    }
    else {
        if (Content[index].qty <= n) {
            Content[index].item = nullptr;
            Content[index].qty = 0;
        } else {
            Content[index].qty -= n;
        }
        
    }
}

void Container::display() {
    int i;

    for (i= 0 ; i < size ; i++){
        if (Content[i].item != nullptr) std::cout<< Content[i].item->getName() <<"["<<Content[i].qty<<"]"<< std::setw(15-Content[i].item->getName().length());
        else std::cout << "NULL[0]"<< std::setw(10);
        

        if ((i+1)%(size/3)==0) {
            std::cout<<std::endl;
        }
        else{
            // std::cout << std::setw(10-Content[i].item->getName().length());
            // cout.width();;
        }
        
    }
}

void Container::move(Container& src, int srcIdx, Container& dst, int dstIdx) {

}

void Container::move(Container& src, int srcIdx, Container& dst, int dstIdx, int n) {

}
