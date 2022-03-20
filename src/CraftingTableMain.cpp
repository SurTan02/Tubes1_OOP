#include "../include/CraftingTable.hpp"


// Buat compile jika anda malas
// g++ --std=c++17 src/CraftingTableMain.cpp  src/CraftingTable.cpp src/Container.cpp src/Tool.cpp src/NonTool.cpp src/Item.cpp src/Recipe.cpp src/readFile.cpp -o tes
vector<Item*> listItem;
vector<Recipe> recipes;

int main(){
    //Inisiasi Inventory
    Container inventory(27);

    CraftingTable craftingTable;
    
    
    //Tes ListItem
    listItem.push_back(new Tool(0,"Tool1",10));
    listItem.push_back(new Tool(1,"Tool2",10));
    listItem.push_back(new Tool(2,"Tool3",10));
    listItem.push_back(new NonTool(3,"NonTool1",ItemType::Log));
    listItem.push_back(new NonTool(4,"NonTool2",ItemType::Stone));
    listItem.push_back(new NonTool(5,"NonTool3",ItemType::Plank));
    
    

    try{
        cout << inventory.getItem(0).item;
    } catch (Exception &e){
        std::cout<<e.what();
    }
    //insert 3 Nontool ke inventory
    inventory.insert(32,*listItem[3]);
    inventory.insert(32,*listItem[4]);
    inventory.insert(32,*listItem[5]);
    
    //insert 3 Tool1 ke inventory
    inventory.insert(*listItem[0],1);
    inventory.insert(*listItem[1],10);
    inventory.insert(*listItem[2],5);
    

    
    craftingTable.display();
    std::cout<<"-----------------------------------\n";

    recipes = readConfigRecipes();
    cout<<"resep "<<recipes.size()<<endl;
    
     
    for (int i=0 ; i < recipes.size(); i++){
        cout<<recipes[i].getItemName()<<endl;
    }

    try{
        craftingTable.craft(inventory);
    } catch(Exception &e){
        std::cout<<e.what();
        cout<<"TESCATCH\n";
    }
    cout<<"TESLUAR\n";
    
    
    cout<<listItem.size()<<endl;
    for (int i=0 ; i < listItem.size(); i++){

        cout<<i<<". "<<listItem[i]->getName()<<endl;
        delete listItem[i];
    }
    return 0;
}

