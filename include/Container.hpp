#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <iostream>
#include <array>
using namespace std;

typedef struct slot {
    Item* item;
    int qty;
} Slot;


class Container {
    private:
        int size;
        Slot* Content;

    public:
        Container(int size);
        ~Container();
        Slot getItem(int index);
        int getSize();
        void insert(int n, Item& itemX);
        void discard(int index, int n);
        void display();
};

#endif