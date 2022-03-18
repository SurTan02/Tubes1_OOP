#include "../include/Container.hpp"

// Buat compile jika anda malas
// g++ src/InventoryMain.cpp src/Container.cpp src/Tool.cpp src/NonTool.cpp src/Item.cpp -o tes
vector<Item*> listItem;

int main(){
    listItem.push_back(new Tool(0,NULL_ITEM,0));
    listItem.push_back(new Tool(1,"list1",10));

    Container x(27);
    Tool t(15, "TOol", 10);
    // Tool q(1, "N", 5);
    NonTool q(5, "2", ItemType::Plank);
    // NonTool q(1, "log", ItemType::Plank);

    
    
    
    Tool t1 = Tool(listItem[1]->getID(), "t1", 10);
    // t1 = Tool(listItem[1]->getID(), "t1", 10);
    
    //Inventory[0] = "t1" == 9
    x.insert(1,  t1);

    //inventory[1] = "Tool" ==8
    x.insert(64,q);


    //Inventory[2] = "The new t1" == 7
    t1 = Tool(listItem[1]->getID(), "the new t1", 10);
    // x.insert(1, Tool(listItem[1]->getID(), "the new t1", 10));
    x.insert(1, t1);
    x.insert(1, *listItem[1]);
    for (int i = 0 ; i< 27 ; i ++ ){
        try{
            x.insert(1, t1);
        }
        catch (Exception &e){
            std::cout<<e.what();
        }
    }
    // x.insert(1, *listItem[1]);
    // std::cout<<"ID: "<<x.getItem(29).item->getID()<<" ";
    // x.insert(1, *listItem[1]);
    // x.insert(1, *listItem[1]);
    // x.insert(1, *listItem[1]);
    // x.insert(1, *listItem[1]);
    // x.insert(1,t);
    // x.insert(5,q);
    // x.insert(5,q);
    // x.insert(63,q);
    // x.discard(2,20);
    // x.discard(1,1);
    // std::cout<<x.getItem(0)->getID()<<"\n";
    // std::cout<<x.getItem(0)->getName()<<"\n";
    ((Tool*) x.getItem(0).item)->use();
    ((Tool*) x.getItem(1).item)->use();
    ((Tool*) x.getItem(1).item)->use();
    ((Tool*) x.getItem(2).item)->use();
    ((Tool*) x.getItem(2).item)->use();
    ((Tool*) x.getItem(2).item)->use();
    std::cout<< ((Tool*) x.getItem(0).item)->getDurability()<<"\n";
    // std::cout<< ((Tool*) x.getItem(1).item)->getDurability()<<"\n";
    std::cout<< ((Tool*) x.getItem(2).item)->getDurability()<<"\n";
    // std::cout<< <<"\n";


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

    delete listItem[0];
    delete listItem[1];
    // delete listItem[0];
    
    // std::cout<<x.getItem(1)->getType()<<"\n";
    // std::cout<<x.getItem(1)->getType();

}