#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "Exception.hpp"
#include <iostream>
using namespace std;

class Container {
    const int MAX_SLOT_QTY = 64;

    typedef struct slot {
        Item* item;
        int qty;
    } Slot;

    protected:
        int size;
        Slot* Content;

    public:
        Container(int size);
        ~Container();
        Slot getItem(int index);
        int getSize();
        void insert(int n, Item& itemX);
        void insert(Item& itemX, int durability);
        void insert(int n, Item& itemX, int index);
        void discard(int index, int n);
        void display();
        static void move(Container& src, int srcIdx, Container& dst, int dstIdx);
        static void move(Container& src, int srcIdx, Container& dst, int dstIdx, int n);
        static void swap(Container& src, int srcIdx, Container& dst, int dstIdx);
};

#endif