#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <array>
#include <vector>
#include <iterator>

#include "Container.hpp"

typedef struct Recipe 
{
    std::array<Item, 9> recipe;
    std::unique_ptr<Item> output;
};

class CraftingTable : Container 
{
    private:
        
    public:
        CraftingTable(); 
        friend std::unique_ptr<Item> craft(CraftingTable, std::vector<Recipe>);
};

#endif