#include "../include/Container.hpp"

// Buat compile jika anda malas
// g++ src/InventoryMain.cpp src/Container.cpp src/Tool.cpp src/NonTool.cpp src/Item.cpp -o tes
vector<Item*> listItem;

int main(){
    listItem.push_back(new Tool(0,NULL_ITEM,0));
    listItem.push_back(new Tool(1,"aaa",0));

    Container x(27);
    Tool t(15, "TOol", 10);
    // Tool q(1, "N", 5);
    NonTool q(5, "Wood", ItemType::Plank);
    // NonTool q(1, "log", ItemType::Plank);
    // std::unique_ptr<Item> t = std::make_unique<Tool>(1, "axe", 1000);
    // std::unique_ptr<Item> q = std::make_unique<NonTool>(1, "log", ItemType::Plank);
    
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1, *listItem[1]);
    x.insert(1,t);
    x.insert(5,q);
    x.insert(5,q);
    x.insert(63,q);
    // x.discard(2,20);
    // x.discard(1,1);
    x.insert(1,q);
    // std::cout<<x.getItem(0)->getID()<<"\n";
    // std::cout<<x.getItem(0)->getName()<<"\n";
    std::cout<< ((Tool*) x.getItem(0).item)->getDurability()<<"\n";


    // Tool* peek = std::dynamic_cast<Tool*>(temp.get());
    // peek->getDurability()

    // for (int i=0; i < x.getSize(); i++){
    //     std::cout<<i+1<<". ";
    //     std::cout<<"ID: "<<x.getItem(i).item->getID()<<" ";
    //     std::cout<<"Name: "<<x.getItem(i).item->getName()<<" ";
    //     std::cout<<"Type: "<<x.getItem(i).item->getTypeToString();
    //     std::cout<<"QTY: "<<x.getItem(i).qty<<std::endl;
    // }
    x.display();
    // q.addQuantity(10);
    // std::cout<<x.getItem(1)->getID()<<"\n";
    // std::cout<<x.getItem(1)->getName()<<"\n";
    // std::cout<<x.getItem(1)->getQuantity()<<"\n";


    
    // std::cout<<x.getItem(1)->getType()<<"\n";
    // std::cout<<x.getItem(1)->getType();

}