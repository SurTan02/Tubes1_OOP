#ifndef __READ__FILE_HPP__
#define __READ__FILE_HPP__

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "Recipe.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>

using namespace std;

// Menentukan itemType dari string type
ItemType getItemType(string);

// Membaca item.txt
vector <Item*> readConfigItem();

// Membaca recipes yang tersedia
void readConfigRecipes();

// Menentukan ItemType berdasarkan nama Item
string getIDandTypefromName(string);

#endif