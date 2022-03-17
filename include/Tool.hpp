#ifndef TOOL_HPP
#define TOOL_HPP

#include "Item.hpp"

class Tool : public Item
{
private:
    int durability;
public:
    Tool(int id, std::string name, int durability);
    Tool operator=(const Tool& other);
    int getDurability();
    void repair(int n);
    void use();
    void output() override;
};

#endif // TOOL_HPP
