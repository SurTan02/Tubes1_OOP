#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <array> 



class Inventory {
    private:
        int size;
        // std::array<Item,5> COn
        // Item** Content = new Item*[27];
        Item* Content[27];


    public:
        Inventory();
        ~Inventory();
        Item* getItem(int index);
        int getSize();
        void insert(int n, Item& itemX);
        void discard(int index, int n, Item& itemX);
};


#endif