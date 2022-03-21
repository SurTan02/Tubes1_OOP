#include "../include/Item.hpp"
#include <string>
using namespace std;

Item::Item(int id, string name, ItemType type) :
    id(id),
    name(name),
    type(type)
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

string Item::getTypeToString() {
    switch (type){
        case ItemType::None:
            return "NONE";
        case ItemType::Log:
            return "LOG";
        case ItemType::Plank:
            return "PLANK";
        case ItemType::Stone:
            return "STONE";
        case ItemType::Tool:
            return "TOOL";
        default:
            return "ERROR";
            break;
        }

}
