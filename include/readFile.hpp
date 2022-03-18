#ifndef __READ__FILE_HPP__
#define __READ__FILE_HPP__

#include "../include/Item.hpp"
#include "../include/Tool.hpp"
#include "../include/NonTool.hpp"
#include "../include/Recipe.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>

// Menentukan itemType dari string type
ItemType getItemType(string);

// Membaca item.txt
vector <Item*> readConfigItem();

// Membaca recipes yang tersedia
vector <Recipe> readConfigRecipes();

// Menentukan ItemType berdasarkan nama Item
string getIDandTypefromName(string);

#endif