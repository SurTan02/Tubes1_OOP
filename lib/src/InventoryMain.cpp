#include "../Header/Inventory.hpp"

int main(){
    Inventory x;
    Tool t(15, "TES", 5);
    // Tool q(1, "N", 5);
    NonTool q(5, "nontool", ItemType::Plank);
    // NonTool q(1, "log", ItemType::Plank);
    // std::unique_ptr<Item> t = std::make_unique<Tool>(1, "axe", 1000);
    // std::unique_ptr<Item> q = std::make_unique<NonTool>(1, "log", ItemType::Plank);
    
    x.insert(1,t);
    x.insert(1,t);
    x.insert(5,q);
    // std::cout<<x.getItem(0)->getID()<<"\n";
    // std::cout<<x.getItem(0)->getName()<<"\n";
    // // std::cout<<x.getItem(0)->getDurability()<<"\n";
    for (int i=0; x.getSize() ;i++){
        std::cout<<i+1<<". ";
        std::cout<<x.getItem(i)->getID()<<" ";
        std::cout<<x.getItem(i)->getName()<<" ";
        std::cout<<x.getItem(i)->getQuantity()<<"\n";
    }
    
    // q.addQuantity(10);
    // std::cout<<x.getItem(1)->getID()<<"\n";
    // std::cout<<x.getItem(1)->getName()<<"\n";
    // std::cout<<x.getItem(1)->getQuantity()<<"\n";


    
    // std::cout<<x.getItem(1)->getType()<<"\n";
    // std::cout<<x.getItem(1)->getType();

}