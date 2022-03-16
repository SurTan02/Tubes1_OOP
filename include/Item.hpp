#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#define NULL_ITEM "NULLITEM"

#include <string>
#include <cstdint>
#include <vector>
using namespace std;

enum class ItemType {None, Log, Plank, Stone, Tool};

class Item
{
    protected:
        ItemType type;
        int id;
        string name;

    public:
        Item();
        Item(int id, string name, ItemType type);
        int getID();
        string getName();
        ItemType getType();
        string getTypeToString();
        virtual void output() = 0;
};

vector<Item> listItem;

#endif // ITEM_HPP_INCLUDED
