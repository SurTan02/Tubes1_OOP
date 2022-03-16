// YANG BELUM KELAR
// addQuantity
// realisasi output

#include "../include/NonTool.hpp"

NonTool::NonTool(int id, std::string name, ItemType type) :
    Item(id, name, type)
{}

NonTool NonTool::operator=(const NonTool& other) {
    NonTool n(other.id, other.name, other.type);
    return n;
}

void NonTool::output() {
    //TODO
}
