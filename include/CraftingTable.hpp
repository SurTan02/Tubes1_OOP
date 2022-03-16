#ifndef CRAFTING_TABLE_HPP_INCLUDED
#define CRAFTING_TABLE_HPP_INCLUDED

#include <array>
#include <vector>
#include <iterator>

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"

typedef struct Recipe 
{
    std::array<Item, 9> recipe;
    std::unique_ptr<Item> output;
};

class CraftingTable
{
private:
    std::array<Item, 9> input;
public:
    CraftingTable();
    ~CraftingTable();
    std::array<Item, 9> getInput();
    void insert(std::unique_ptr<Item>, int);
    std::unique_ptr<Item> discard(int);
    friend std::unique_ptr<Item> craft(CraftingTable, std::vector<Recipe>);
};

#endif