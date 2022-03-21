#include "../include/readFile.hpp"

vector<Recipe*> recipes;
vector<Item*> listItem;

ItemType getItemType(string type){
	if(type == "LOG")		    {return ItemType::Log;}
	else if(type == "PLANK")	{return ItemType::Plank;}
	else if(type == "STONE")	{return ItemType::Stone;}
	else if(type == "TOOL")		{return ItemType::Tool;}
    else				        {return ItemType::None;}
}

// Read All Config
void readConfigItem(){

    string configPath = "config/item.txt";
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

}

// Read All Recipee
void readConfigRecipes(){
    string configPath = "config/recipe/";
    
    DIR *dir;
    struct dirent *ent;

    //vector <Recipe> recipes;
    int lineRead = 0;
    string row , col , itemName , quantity;
    string material1 , material2 , material3;
    int idx_bp = 0;

    /**
     * .c_str digunakan
     * untuk mendapatkan
     * const char* dari
     * sebuah class
     * std::string
     */
    if ((dir = opendir(configPath.c_str())) != NULL) {		/* print all the files and directories within directory */
        int n = 2;
        int idx = 0;
         
        while ((ent = readdir(dir)) != NULL) {
            lineRead = 0;
            idx_bp = 0;
            
            if(n != 0)	{n--;}
            else {  // read file path
                idx++;
                ifstream itemConfigFile(configPath + ent->d_name);
                
                Recipe* tempRecipe = new Recipe();
                
                for (string line; getline(itemConfigFile, line);) {
    
                    // initialize blueprint's materials
                    material1 = NULL_ITEM;
                    material2 = NULL_ITEM;
                    material3 = NULL_ITEM;
                    
                    stringstream words(line);
                    lineRead++;
                    
                    if(lineRead == 1){
                        
                        words >> row >> col;
                        tempRecipe->setRow(stoi(row));
                        tempRecipe->setColumn(stoi(col));
                        lineRead += 3 - stoi(row);          //adjust total line of recipe.txt
                    }else if (lineRead == 5){               // last line on recipe.txt
                        
                        words >> itemName >> quantity;
                        tempRecipe->setItemName(itemName);
                        tempRecipe->setCreatedProduct(stoi (quantity));
                    }else{
                        if(tempRecipe->getColumn() == 1)       {words >> material1;}
                        else if (tempRecipe->getColumn() == 2) {words >> material1 >> material2;}
                        else if (tempRecipe->getColumn() == 3) {words >> material1 >> material2 >> material3;}
                        tempRecipe->setBlueprint(idx_bp , material1);
                        tempRecipe->setBlueprint(idx_bp+1 , material2);
                        tempRecipe->setBlueprint(idx_bp+2 , material3);
                        idx_bp += 3;
                    }  
                }     
                recipes.push_back(tempRecipe);    
            }
        }
        closedir (dir);
    } else {perror ("");}	/* could not open directory */

}

// get ID and ItemType of an item
int getIDfromName(string nama){
    string configPath = "config/item.txt";

	string id , name, type , typeTool;
  	ifstream itemConfigFile(configPath);

    for(auto i = listItem.begin(); i != listItem.end(); ++i){
        if((*i)->getName() == nama){
            return (*i)->getID();
        }
    }
    return 0; 
}

string getTypefromName(string nama){
    for(auto i = listItem.begin(); i != listItem.end(); ++i){
        if((*i)->getName() == nama){
            return (*i)->getTypeToString();
        }
    }
    return NULL_ITEM; 
}