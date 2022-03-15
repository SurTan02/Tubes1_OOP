// TODO:
// use durabilitynya sesuaikan
// realisasi output

#include "Tool.hpp"

Tool::Tool(int id, std::string name, int durability) :
    Item(id, name, ItemType::Tool, 1),
    durability(durability)
{}

Tool Tool::operator=(const Tool& other) {
    Tool t(other.id, other.name, other.durability);
    return t;
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

void Tool::output() {

}
