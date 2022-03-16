#include "../header/Item.hpp"

Item::Item(int id, std::string name, ItemType type, std::uint64_t quantity) :
    id(id),
    name(name),
    type(type),
    quantity(quantity)
{}

int Item::getID() {
    return id;
}

std::string Item::getName() {
    return name;
}

ItemType Item::getType(){
    return type;
}

std::uint64_t Item::getQuantity() {
    return quantity;
}
