#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <array>
#include <vector>
#include <iterator>

#include "Container.hpp"
#include "Recipe.hpp"

class CraftingTable : Container 
{
    public:
        CraftingTable(); 
        string getName(int n);
        bool isEmpty();
        bool isTool();
        bool isNonTool();
        Item* craft(std::vector<Recipe>);
};

#endif