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
void readConfigItem();

// Membaca recipes yang tersedia
void readConfigRecipes();

// Menentukan ID berdasarkan nama Item
int getIDfromName(string);

// Menentukan ItemType berdasarkan nama Item
string getTypefromName(string);

extern vector<Recipe*> recipes;
extern vector<Item*> listItem;

#endif