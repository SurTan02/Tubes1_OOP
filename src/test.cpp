#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <list>
#include "../include/readFile.hpp"
#include "../include/CraftingTable.hpp"
using namespace std;

// void printWords(string str)
// {
// 	// word variable to store word
// 	string word1 , word2 , word3;

// 	// making a string stream
// 	stringstream iss(str);

// 	// Read and print each word.
//     iss >> word1 >> word2 >> word3;
// 	cout << word1 << " hi1" << endl;
// 	cout << word2 << " hi2"<< endl;
// 	cout << word3 << " hi3"<< endl;
// }

// // Driver code
// int main()
// {
// 	string s = "sky is blue";
// 	printWords(s);
// 	return 0;
// }

#include <stdio.h>


int main() {
    readConfigRecipes();
    /*
	string configPath = "../config";
	// string itemConfigPath = configPath + "/item.txt";
    DIR *dir;
    struct dirent *ent;
    cout<<"OPENDIR " << opendir("../config/recipe/") << endl;
    if ((dir = opendir ("../config/recipe/")) != NULL) {
        /* print all the files and directories within directory */ /*
        int n = 2;
        while ((ent = readdir (dir)) != NULL) {
            if(n != 0){
                n--;
            }else{
                ifstream itemConfigFile(configPath + "/recipe/" + ent->d_name);
                for (string line; getline(itemConfigFile, line);) {
                    //get data
                    cout<<line<<endl;
                }
            }
        }
        closedir (dir);
     } else {
        /* could not open directory */ /*
        cout<<"SESUATU"<<endl;
        perror ("");
        return -1;
     }
*/
    // Container inventory(27);

    // CraftingTable craftingTable = CraftingTable();
    
    
    // //Tes ListItem
    // listItem.push_back(new Tool(0,"Tool1",10));
    // listItem.push_back(new Tool(1,"Tool2",10));
    // listItem.push_back(new Tool(2,"Tool3",10));
    // listItem.push_back(new NonTool(3,"NonTool1",ItemType::Log));
    // listItem.push_back(new NonTool(4,"NonTool2",ItemType::Stone));
    // listItem.push_back(new NonTool(5,"NonTool3",ItemType::Plank));
    
    

    // try{
    //     cout << inventory.getItem(0).item;
    // } catch (Exception &e){
    //     std::cout<<e.what();
    // }
    // //insert 3 Nontool ke inventory
    // inventory.insert(32,*listItem[3]);
    // inventory.insert(32,*listItem[4]);
    // inventory.insert(32,*listItem[5]);
    
    // //insert 3 Tool1 ke inventory
    // inventory.insert(*listItem[0],1);
    // inventory.insert(*listItem[1],10);
    // inventory.insert(*listItem[2],5);
    

    
    // craftingTable.display();
    // std::cout<<"-----------------------------------\n";

    // cout<<"resep "<<recipes.size()<<endl;
    // recipes = readConfigRecipes();
     
    // for (int i=0 ; i < recipes.size(); i++){
    //     cout<<recipes[i].getItemName()<<endl;
    // }

    // try{

    //     cout<<"TESTRYASSSS\n";
    //     craftingTable.craft(inventory);
    // } catch(Exception &e){
    //     std::cout<<e.what();
    //     cout<<"TESCATCH\n";
    // }
    // cout<<"TESLUAR\n";
    
    
    // cout<<listItem.size()<<endl;
    // for (int i=0 ; i < listItem.size(); i++){

    //     cout<<i<<". "<<listItem[i]->getName()<<endl;
    //     delete listItem[i];
    // }
    // cout<<"TESLUARSSS\n";
    
     return 0;
}