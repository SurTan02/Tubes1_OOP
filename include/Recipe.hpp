#ifndef __RECIPES__HPP__
#define __RECIPES__HPP__

#include <vector>
#include <string>
#define NULL_ITEM "NULLITEM"
using namespace std;

class Recipe{
    private :
        int row;
        int column;
        vector<string> blueprint;
        string itemName;
        int createdProduct;
    public :
        Recipe(int , int);
        ~Recipe();

        void setRow(int);
        int getRow() const;

        void setColumn(int);
        int getColumn() const;
        
        void setBlueprint(int , string);
        vector<string> getBlueprint();
        string operator[](int);

        void setItemName(string);
        string getItemName() const;

        void setCreatedProduct(int);
        int getCreatedProduct() const;

};

vector<Recipe> recipes;

#endif