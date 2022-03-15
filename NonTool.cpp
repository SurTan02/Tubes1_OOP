// YANG BELUM KELAR
// addQuantity
// realisasi output

#include "NonTool.hpp"

NonTool::NonTool(int id, std::string name, ItemType type) :
    Item(id, name, type, 0)
{}

NonTool NonTool::operator=(const NonTool& other) {
    NonTool n(other.id, other.name, other.type);
    return n;
}

void NonTool::addQuantity(int n) {
    quantity += n;
    if(quantity > 64) {
        // HANDLE YANG LEBIH DARI 64
        quantity = 64;
    }
}
void NonTool::removeQuantity(int n) {
    quantity -= n;
    if(quantity < 0) {
        quantity = 0;
    }
}

void NonTool::output() {
    //TODO
}
