#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <array>
#include <vector>
#include <iterator>
#include <sstream>

#include "Container.hpp"
#include "Recipe.hpp"
#include "readFile.hpp"

class CraftingTable : Container 
{
    private:

    public:
        CraftingTable(); 
        string getName(int n);
        bool isEmpty();
        bool isTool();
        bool isNonTool();
        bool check(vector<string>);
        bool checkMirror(vector<string>);
        bool checkSub(vector<string>, int, int);
        void craft(std::vector<Recipe>, Container);
};

#endif