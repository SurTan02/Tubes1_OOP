#include "../include/Tool.hpp"


Tool::Tool(int id, std::string name, int durability) :
    Item(id, name, ItemType::Tool),
    durability(durability)
{}

Tool& Tool::operator=(const Tool& other) {
    this->id = other.id;  
    this->name = other.name;  
    this->durability = other.durability;
    return *this;
}

int Tool::getDurability(){
    return durability;
}

void Tool::repair(int n) {
    durability += n;
}

void Tool::use() {
    durability -= 1;
}

string Tool::output(int qty) {
    return to_string(id) + string(":") + to_string(durability);
}