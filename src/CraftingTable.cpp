#include "../include/CraftingTable.hpp"

CraftingTable::CraftingTable() 
{
    this->input.fill(Tool(0, "NULLITEM", 0));
}

CraftingTable::~CraftingTable() { }

std::array<Item, 9> CraftingTable::getInput() {
    return this->input;
}

void CraftingTable::insert(std::unique_ptr<Item> item, int n) 
{
    std::get<n>(this->input) = item;
}

std::unique_ptr<Item> CraftingTable::discard(int n) 
{
    return std::get<n>(this->input);
}

std::unique_ptr<Item> craft(CraftingTable& craftingTable, std::vector<Recipe>& recipes) 
{
    std::vector<Recipe>::iterator ptr;

    for (ptr = recipes.begin(); ptr < recipes.end(); ptr++) {
        if (craftingTable.getInput() == ptr->recipe) {
            return ptr->output;
        }
    }
}