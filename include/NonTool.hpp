#ifndef NONTOOL_HPP
#define NONTOOL_HPP

#include "Item.hpp"

class NonTool : public Item
{
public:
    NonTool(int id, std::string name, ItemType type);
    NonTool operator=(const NonTool& other);
    string output(int qty) override;
};

#endif // NONTOOL_HPP_INCLUDED
