#include "../include/readFile.hpp"

ItemType getItemType(string type){
	if(type == "-")				{return ItemType::None;}
	else if(type == "LOG")		{return ItemType::Log;}
	else if(type == "PLANK")	{return ItemType::Plank;}
	else if(type == "STONE")	{return ItemType::Stone;}
	else if(type == "TOOL")		{return ItemType::Tool;}
}

// Read All Config
vector <Item*> readConfigItem(){
    string configPath = "./config/item.txt";

    vector <Item*> listItem;
	string id , name, type , typeTool;
  	ifstream itemConfigFile(configPath);
    
  	for (string line; getline(itemConfigFile, line);) {
		//get data
		stringstream words(line);
		words >> id >> name >> type >> typeTool;

		if (typeTool == "Tool"){	//craft Tool
			listItem.push_back(new Tool(stoi(id) , name , 10));
		}else{		                //craft nontool
			listItem.push_back(new NonTool(stoi(id) , name , getItemType(type)));
		}
  	}
    return listItem;
}

// Read All Recipee
vector <Recipe> readConfigRecipes(){
    string configPath = "./config/recipe/";
    DIR *dir;
    struct dirent *ent;

    vector <Recipe> recipes;
    int lineRead = 0;
    string row , col , itemName , quantity;
    string material1 , material2 , material3;
    int idx_bp = 0;

    if ((dir = opendir ("config/recipe/")) != NULL) {		/* print all the files and directories within directory */
        int n = 2;
        int idx = 0;
        while ((ent = readdir (dir)) != NULL) {
            if(n != 0)	{n--;}
            else{  // read file path
                idx++;
                ifstream itemConfigFile(configPath + ent->d_name);
                for (string line; getline(itemConfigFile, line);) {
                    // initialize blueprint's materials
                    material1 = NULL_ITEM;
                    material2 = NULL_ITEM;
                    material3 = NULL_ITEM;

                    stringstream words(line);
                    lineRead++;
                    if(lineRead == 1){
                        words >> row >> col;
                        recipes[idx].setRow(stoi (row));
                        recipes[idx].setRow(stoi (col));
                        lineRead += 3 - stoi(row);          //adjust total line of recipe.txt
                    }else if (lineRead == 5){
                        words >> itemName >> quantity;
                        recipes[idx].setItemName(itemName);
                        recipes[idx].setCreatedProduct(stoi (quantity));
                    }else{
                        if(recipes[idx].getColumn() == 1)       {words >> material1;}
                        else if (recipes[idx].getColumn() == 2) {words >> material1 >> material2;}
                        else if (recipes[idx].getColumn() == 3) {words >> material1 >> material2 >> material3;}

                        recipes[idx].setBlueprint(idx_bp , material1);
                        recipes[idx].setBlueprint(idx_bp+1 , material2);
                        recipes[idx].setBlueprint(idx_bp+2 , material3);
                        idx_bp+= 3;
                    }
                }
            }
        }
        closedir (dir);
    } else {perror ("");}									/* could not open directory */

    return recipes;
}

// get ID and ItemType of an item
string getIDandTypefromName(string nama){
    string configPath = "./config/item.txt";

	string id , name, type , typeTool;
  	ifstream itemConfigFile(configPath);

    for (string line; getline(itemConfigFile, line);) {
		//get data
		stringstream words(line);
		words >> id >> name >> type >> typeTool;

        if(name == nama){
            return id + " " + typeTool; 
        }
  	}
}
