#include "../include/Recipes.hpp"
using namespace std;

// default : 
// row = row , column = col
// blueprint = []
// itemName = "NULLITEM"
// createdProduct = 0
Recipe::Recipe(int row , int col) : 
    row(row) , column(col) ,
    itemName(NULL_ITEM) ,
    createdProduct(0)
    {}

Recipe::~Recipe(){
    blueprint.clear();
}

void Recipe::setRow(int row) {
    this->row = row;
}

int Recipe::getRow() const {
    return row;
}

void Recipe::setColumn(int col) {
    this->column = col;
}

int Recipe::getColumn() const {
    return column;
}

void Recipe::setBlueprint(int idx , string item) {
    blueprint[idx] = item;
}

vector<string> Recipe::getBlueprint() {
    return this->blueprint;
}

string Recipe::operator[](int idx){
    return this->blueprint[idx];
}

void Recipe::setItemName(string name) {
    this->itemName = name;
}

string Recipe::getItemName() const {
    return itemName;
}

void Recipe::setCreatedProduct(int quantity) {
    this->createdProduct = quantity;
}

int Recipe::getCreatedProduct() const {
    return this->createdProduct;
}
