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
            return "None";
        case ItemType::Log:
            return "Log";
        case ItemType::Plank:
            return "Plank";
        case ItemType::Stone:
            return "Stone";
        case ItemType::Tool:
            return "Tool";
        default:
            return "ERROR";
            break;
        }

}
