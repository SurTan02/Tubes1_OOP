#include "../include/Container.hpp"

// Buat compile jika anda malas
// g++ src/InventoryMain.cpp src/Container.cpp src/Tool.cpp src/NonTool.cpp src/Item.cpp -o tes
vector<Item*> listItem;

int main(){
    //Inisiasi Inventory
    Container inventory(27);
    
    //Tes ListItem
    listItem.push_back(new Tool(0,"Tool1",10));
    listItem.push_back(new Tool(1,"Tool2",10));
    listItem.push_back(new Tool(2,"Tool3",10));
    listItem.push_back(new NonTool(3,"NonTool1",ItemType::Log));
    listItem.push_back(new NonTool(4,"NonTool2",ItemType::Stone));
    listItem.push_back(new NonTool(5,"NonTool3",ItemType::Plank));
    
    //insert 3 Nontool ke inventory
    inventory.insert(32,*listItem[3]);
    inventory.insert(32,*listItem[4]);
    inventory.insert(32,*listItem[5]);
    
    //insert 3 Tool1 ke inventory
    inventory.insert(1,*listItem[0]);
    inventory.insert(1,*listItem[0]);
    inventory.insert(1,*listItem[0]);
    
    //display
    inventory.display();
    std::cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n";
   
    //Tes Use Tool1 pada index 3 sebanyak 1x;
    ((Tool*) inventory.getItem(3).item)->use();
    
    //Tes Use Tool1 pada index 4 sebanyak 2x;
    ((Tool*) inventory.getItem(4).item)->use();
    ((Tool*) inventory.getItem(4).item)->use();

    //Tes Use Tool1 pada index 5 sebanyak 3x;
    ((Tool*) inventory.getItem(5).item)->use();
    ((Tool*) inventory.getItem(5).item)->use();
    ((Tool*) inventory.getItem(5).item)->use();
    

    //Tampilkan Durability Tool1 
    std::cout<<"Durability pada indeks 3 : "<<((Tool*) inventory.getItem(3).item)->getDurability()<<"\n";
    std::cout<<"Durability pada indeks 4 : "<<((Tool*) inventory.getItem(4).item)->getDurability()<<"\n";
    std::cout<<"Durability pada indeks 5 : "<<((Tool*) inventory.getItem(5).item)->getDurability()<<"\n";

    //UjiCoba Discard Item Indeks 0 Sebanyak 20;
    //UjiCoba Discard Item Indeks 1 Sebanyak 32;
    inventory.discard(0,20);
    inventory.discard(1,32);
    inventory.display();
    std::cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n";
    
    //Ujicoba Insert sampai penuh
    for (int i = 0 ; i< 27 ; i++ ){
        try{
            inventory.insert(64, *listItem[3]);
        }
        catch (Exception &e){
            std::cout<<e.what();
            break;
        }
    }
    inventory.display();
    std::cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n";

    //Discard dari indeks 0-26
    for (int i = 0 ; i< 27 ; i++ ){
        try{
            inventory.discard(i, 64);
        }
        catch (Exception &e){
            std::cout<<e.what();
            break;
        }
    }
    inventory.display();
    std::cout<<"----------------------------------------------------------------------------------------------------------------------------------------\n";

    // Container::move(x, 1, x, 26,10);
    
  




    for (int i=0 ; i < listItem.size(); i++){
        delete listItem[i];
    }
}