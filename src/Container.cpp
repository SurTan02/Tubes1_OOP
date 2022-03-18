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
    // Item* tempItem; 
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
            i++;
        }
        if (flagNull && !found){
            Content[FirstNull].item = &itemX;
            Content[FirstNull].qty = n;
        }
        
    }
    else {
        bool found = false;
        int i = 0;
        while (i < 27 && !found) {
            if (Content[i].item == nullptr) {
                Content[i].item = new Tool(itemX.getID(), itemX.getName(), 10);
                Content[i].qty = 1;
                found = true;
            }
            i++;
        }
        if (!found){
            throw FullInventoryException(); 
        }
    }
}    

void Container::insert(int n, Item& itemX,int index){
    if (itemX.getType() != ItemType::Tool) {                            //CEK ITEM NONTOOL
        if (Content[index].item== nullptr){                             //CEK SLOT KOSONG/GA
            Content[index].item = &itemX;
            Content[index].qty = n;
        }
        else if (Content[index].item->getName() == itemX.getName()) {   //CEK ITEM PADA SLOT SAMA ATAU GA
            Content[index].qty += n;
        }

    } else {                                                            //ITEM NONTOOL
            if (Content[index].item == nullptr){ 
            Content[index].item = &itemX;
            Content[index].qty = 1;       
        }
    }
}


void Container::discard(int index, int n) {
    if (Content[index].item->getType() == ItemType::Tool) {

        delete Content[index].item;
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
        std::cout << std::setw(23);
        if (Content[i].item != nullptr)
        {
            string out;
            string quant;
            quant = to_string(Content[i].qty);
            out = Content[i].item->getName() + "[" + quant + "]";
            std::cout << out << std::setw(23);
        }
        else std::cout << "NULL[0]"  << std::setw(23);
        

        if ((i+1)%(size/3)==0) {
            std::cout<<std::endl;// << std::setw(-25);
        }        
    }
}


void Container::move(Container& src, int srcIdx, Container& dst, int dstIdx) {
    move(src, srcIdx, dst, dstIdx, src.Content[srcIdx].qty);
}

void Container::move(Container& src, int srcIdx, Container& dst, int dstIdx, int n) {
    Slot srcSlot = src.Content[srcIdx];
    Slot dstSlot = dst.Content[dstIdx];
    Slot temp;
    
    if (srcSlot.item == nullptr) {
        
        throw EmptySourceException();
    }
    
    // Throw exception or swap?? Specification unclear
    if (srcSlot.item != dstSlot.item && dstSlot.item != nullptr) {
       
        throw DifferentItemTargetException();
    }
    if (n > srcSlot.qty) {
    
        throw NotEnoughItemException();
    }
    
    try { 
        if (n + dstSlot.qty <= 64) {
            dst.insert(n,*srcSlot.item,dstIdx);
            src.discard(srcIdx, n);            
        }
        else {
            std::cout<<"TES7\n";
            dst.insert(64 - dstSlot.qty, *srcSlot.item, dstIdx);
            src.discard(srcIdx, 64 - dstSlot.qty);
        }
    } catch (Exception& e) {
        cout << e.what() << endl;
    }
}
