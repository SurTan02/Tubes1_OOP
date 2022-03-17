#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <iostream>
#include <array>
using namespace std;

class Container {
    typedef struct slot {
        Item* item;
        int qty;
    } Slot;

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
        void move(Container& src, int srcIdx, Container& dst, int dstIdx);
        void move(Container& src, int srcIdx, Container& dst, int dstIdx, int n);
};

#endif