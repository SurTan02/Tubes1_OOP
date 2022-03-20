#include "../include/CraftingTable.hpp"


// Buat compile jika anda malas
// g++ --std=c++17 src/CraftingTableMain.cpp  src/CraftingTable.cpp src/Container.cpp src/Tool.cpp src/NonTool.cpp src/Item.cpp src/Recipe.cpp src/readFile.cpp -o tes

int main(){
    //Inisiasi Inventory
    Container inventory(27);
    CraftingTable craftingTable;
    
    
    //Tes ListItem
    readConfigRecipes();
    cout<<"Tidak "<<recipes.size();
    readConfigItem();
    

    try{
        cout << inventory.getItem(0).item;
    } catch (Exception &e){
        std::cout<<e.what();
    }
    //insert 3 Nontool ke inventory
    inventory.insert(32,*listItem[3]); std::cout<<"3 ";
    inventory.insert(32,*listItem[4]); std::cout<<"4 ";
    inventory.insert(32,*listItem[5]); std::cout<<"5 ";
    
    //insert 3 Tool ke inventory
    inventory.insert(*listItem[0],1); std::cout<<"6 ";
    inventory.insert(*listItem[1],10); std::cout<<"7 ";
    inventory.insert(*listItem[2],5); std::cout<<"8 ";
    inventory.insert(1,*listItem[10],26); std::cout<<"9"; 

    inventory.display();
    std::cout<<"---------------B4 move--------------------\n";
    craftingTable.display();
    std::cout<<"-----------------------------------\n";

    // Container::move(Container& src, int srcIdx, Container& dst, int dstIdx, int n)
    // Container::move(inventory,3,craftingTable, 0,1);
    // for (int i = 0 ; i < 9 ; i++){
    //     craftingTable.insert(1,*listItem[10],i);
    // }
    craftingTable.insert(1,*listItem[0],4);
    inventory.display();
    std::cout<<"-----------------B4 craft------------------\n";
    craftingTable.display();
    std::cout<<"-----------------------------------\n";
    //readConfigRecipes();
    cout<<"resep "<<recipes.size()<<endl;
    
    // PRINT LIST RECIPES -------------------------------------------
    // for (int i=0 ; i < recipes.size(); i++){
    //     cout<<recipes[i]->getItemName() <<" + "<< recipes[i]->getCreatedProduct()<<endl;
    //      delete recipes[i];
    // }

    // CRAFT ITEM
    try{
        cout<<"TES CRAFT\n";
        craftingTable.craft(inventory);
    } catch(Exception &e){
        std::cout<<e.what();
        //cout<<"TESCATCH\n";
    }
    inventory.display();
    std::cout<<"-----------------------------------\n";
    craftingTable.display();
    std::cout<<"-----------------------------------\n";
    
    // PRINT LIST ITEM -------------------------------------------
    cout<<listItem.size()<<endl;
    for (int i=0 ; i < listItem.size(); i++){

        // cout<<i<<". "<<listItem[i]->getName()<<endl;
        delete listItem[i];
    }
    
    return 0;
}