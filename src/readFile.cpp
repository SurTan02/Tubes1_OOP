#include "../include/readFile.hpp"

vector<Recipe> recipes;

ItemType getItemType(string type){
	if(type == "-")				{return ItemType::None;}
	else if(type == "LOG")		{return ItemType::Log;}
	else if(type == "PLANK")	{return ItemType::Plank;}
	else if(type == "STONE")	{return ItemType::Stone;}
	else if(type == "TOOL")		{return ItemType::Tool;}
}

// Read All Config
vector <Item*> readConfigItem(){
    string configPath = "../config/item.txt";

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
// vector <Recipe> readConfigRecipes(){
vector<Recipe> readConfigRecipes(){
    string configPath = "../config/recipe/";
    
    DIR *dir;
    struct dirent *ent;

    //vector <Recipe> recipes;
    int lineRead = 0;
    string row , col , itemName , quantity;
    string material1 , material2 , material3;
    int idx_bp = 0;
/*
    cout<<"OPENDIR " << (opendir("../config/recipe/") == NULL) << endl;

    struct dirent *d;
    DIR *dr;
    dr = opendir("../config/recipe/");
    if(dr!=NULL)
    {
        cout<<"List of Files & Folders:-\n";
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            cout<<d->d_name<<endl;
        }
        closedir(dr);
    }
    else
        cout<<"\nError Occurred!";
    cout<<endl;
*/
    if ((dir = opendir("../config/recipe/")) != NULL) {		/* print all the files and directories within directory */
        int n = 2;
        int idx = 0;
        cout<<"masuk dir" <<endl; 
        while ((ent = readdir(dir)) != NULL) {
            // cout<< ent <<" + " << *dir<<endl;  
            
            if(n != 0)	{n--;}
            else {  // read file path
                idx++;
                ifstream itemConfigFile(configPath + ent->d_name);
                cout << configPath + ent->d_name << endl;
                Recipe tempRecipe;

                for (string line; getline(itemConfigFile, line);) {
    
                    // initialize blueprint's materials
                    material1 = NULL_ITEM;
                    material2 = NULL_ITEM;
                    material3 = NULL_ITEM;
                    
                    stringstream words(line);
                    lineRead++;
                    cout<<"'for' line : " << line<<endl;
                    if(lineRead == 1){
                        cout<<"lineRead1 : " << line<<endl;
                        words >> row >> col;
                        tempRecipe.setRow(stoi(row));
                        tempRecipe.setColumn(stoi(col));
                        lineRead += 3 - stoi(row);          //adjust total line of recipe.txt
                    }else if (lineRead == 5){               // last line on recipe.txt
                        cout<<"last Line : " << line<<endl;
                        words >> itemName >> quantity;
                        tempRecipe.setItemName(itemName);
                        tempRecipe.setCreatedProduct(stoi (quantity));
                    }else{
                        cout<<"other line : " << line<<endl;
                        if(tempRecipe.getColumn() == 1)       {words >> material1;}
                        else if (tempRecipe.getColumn() == 2) {words >> material1 >> material2;}
                        else if (tempRecipe.getColumn() == 3) {words >> material1 >> material2 >> material3;}

                        tempRecipe.setBlueprint(idx_bp , material1);
                        tempRecipe.setBlueprint(idx_bp+1 , material2);
                        tempRecipe.setBlueprint(idx_bp+2 , material3);
                        idx_bp+= 3;
                    }  
                } 
                recipes.push_back(tempRecipe);
            }

            cout<<"size recipe" <<recipes.size() <<endl;  
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
            return id + " " + type + " " + typeTool; 
        }
  	}
}
