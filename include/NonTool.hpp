#ifndef NONTOOL_HPP_INCLUDED
#define NONTOOL_HPP_INCLUDED

#include "Item.hpp"

class NonTool : public Item
{
public:
    NonTool(int id, std::string name, ItemType type);
    NonTool operator=(const NonTool& other);
    void output() override;
};

#endif // NONTOOL_HPP_INCLUDED
