#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#include <string>
#include <cstdint>

enum class ItemType {None, Log, Plank, Stone, Tool};

class Item
{
protected:
    ItemType type;
    int id;
    std::string name;
    std::uint64_t quantity;
public:
    Item(int id, std::string name, ItemType type, std::uint64_t quantity);
    int getID();
    std::string getName();
    ItemType getType();
    std::uint64_t getQuantity();
    virtual void output() = 0;
};

#endif // ITEM_HPP_INCLUDED
