#include "../include/Recipe.hpp"
using namespace std;

// default : 
// row = row , column = col
// blueprint = []
// itemName = "NULLITEM"
// createdProduct = 0
Recipe::Recipe() : row(0), column(0), itemName(NULL_ITEM), createdProduct(0) {
    this->blueprint = new string[9];
    for (int i = 0; i < 9; i++) {
        this->blueprint[i] = NULL_ITEM;
    }
}

Recipe::Recipe(int row , int col) : 
    row(row) , column(col) ,
    itemName(NULL_ITEM) ,
    createdProduct(0)
{
    this->blueprint = new string[9];
    for (int i = 0; i < 9; i++) {
        this->blueprint[i] = NULL_ITEM;
    }
}

Recipe::~Recipe(){
    delete[] this->blueprint;
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
    this->blueprint[idx] = item;
}

string* Recipe::getBlueprint() {
    return this->blueprint;
}

string Recipe::operator[](int idx){
    return this->blueprint[idx];
}

void Recipe::setItemName(string name) {
    this->itemName = name;
}

string Recipe::getItemName() const {
    return this->itemName;
}

void Recipe::setCreatedProduct(int quantity) {
    this->createdProduct = quantity;
}

int Recipe::getCreatedProduct() const {
    return this->createdProduct;
}
