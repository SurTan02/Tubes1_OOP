#include "../include/Container.hpp"
#include <iomanip>
//Constructor

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

//Mengembalikan Slot pada Content[index]
Container::Slot Container::getItem(int index) {
    if (Content[index].item == nullptr){
        throw EmptySourceException();
    }
    return Content[index];
}

int Container::getSize() {
    return this->size;
}

//BIKIN INSERT KHUSUS ITEM
void Container::insert(Item& itemX, int durability){
    bool found = false;
    int i = 0;
        while (i < size && !found) {
            if (Content[i].item == nullptr) {
                Content[i].item = new Tool(itemX.getID(), itemX.getName(), 10);
                Content[i].qty = 1;
                found = true;
            }
            i++;
        }   
    
    //Kalau Tidak ditemukan slot yang bisa diinsert menandakan container penuh
    if (!found){
        throw FullInventoryException(); 
    }
}


//Insert Item NonTool, Digunakan pada command give / craft 
void Container::insert(int n, Item& itemX) {

    bool flagNull = false;
    bool found = false;
    int FirstNull,temp,i;
    i = 0;

    //Jika Item yang ditambahkan adalah nontool
    
    while (i < size && !found) {
            if (Content[i].item == nullptr) {

                //Penanda Slot yang kosong
                if (!flagNull){
                    flagNull = true;
                    FirstNull = i;
                }
            }
            //Kasus apabila ada item sama tetapi belum penuh
            else if (Content[i].item->getName() == itemX.getName() && Content[i].qty < 64) {
                temp = Content[i].qty + n;
                if (temp > 64){
                    Content[i].qty = 64;
                    insert(temp-64,itemX);
                }
                else Content[i].qty = temp;
                
                found = true;
            }
            i++;
    }
    
    //Jika tidak ada item serupa, tambahkan pada slot kosong
    if (flagNull && !found){
        Content[FirstNull].item = &itemX;
        /**
         * apabila jumlah item lebih banyak daripada 64
         */
        if(n > 64) {
            Content[FirstNull].qty = 64;
            insert(n-64, itemX);
            found = true;
        /**
         * apabila jumlah item tidak lebih banyak daripada 64
         */
        } else {
            Content[FirstNull].qty = n;
            found = true;
        }
    }
    //Kalau Tidak ditemukan slot yang bisa diinsert menandakan container penuh
    if (!found){
        throw FullInventoryException(); 
    }
}    

void Container::insert(int n, Item& itemX,int index){
    if (itemX.getType() != ItemType::Tool) {                            //CEK ITEM NONTOOL
        if (Content[index].item== nullptr){                             //cek apakah slot kosong
            Content[index].item = &itemX;
            Content[index].qty = n;
        }
        else if (Content[index].item->getName() == itemX.getName()) {   //CEK ITEM PADA SLOT SAMA ATAU GA
            Content[index].qty += n;
        }

    } else {                                                            //ITEM TOOL
            if (Content[index].item == nullptr){ 
            Content[index].item = &itemX;
            Content[index].qty = 1;       
        }
    }
}


void Container::discard(int index, int n) {

    if (Content[index].qty < n){
        throw NotEnoughItemException();
    }
    else if (Content[index].item == nullptr){
        throw EmptySourceException();
    }
    //Cek apakah Item pada index merupakan tool, jika iya kosongkan slot
    
    else if (Content[index].item->getType() == ItemType::Tool) {
        delete Content[index].item;
        Content[index].item = nullptr;
        Content[index].qty = 0;
    }
    //Kasus Apabila item Yang ingin dihapus adalah NonTool;
    else {
        //Kasus sama apabila jumlah n > qty item
        if (Content[index].qty == n){
            Content[index].item = nullptr;
        Content[index].qty = 0;

        } else{
            Content[index].qty -= n;
        }
        
        
    }
}


void Container::display() {
    int i;
    for (i= 0 ; i < size ; i++){
        std::cout << std::setw(15);
        if (Content[i].item != nullptr)
        {
            string out;
            string quant;
            quant = to_string(Content[i].qty);
            out = Content[i].item->getName() + "[" + quant + "]";
            std::cout << out << std::setw(15);
        }
        else std::cout << "NULL[0]"  << std::setw(15);
        

        if ((i+1)%(size/3)==0) {
            std::cout<<std::endl;// << std::setw(-25);
        }        
    }
    std::cout << std::setw(0);
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
        // temp = dstSlot; 
        // dstSlot = srcSlot; 
        // srcSlot = temp; 

        //Craft
        // try
        //Insert(Inventory,Hasil)           //Penuh
        //Discard(CraftTable,Hasil)         //Item tab
        // catch
        // 
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
            dst.insert(64 - dstSlot.qty, *srcSlot.item, dstIdx);
            src.discard(srcIdx, 64 - dstSlot.qty);
        }
    } catch (Exception& e) {
        cout << e.what() << endl;
        
    }
    
}
