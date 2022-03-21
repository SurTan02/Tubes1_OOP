#ifndef __RECIPES__HPP__
#define __RECIPES__HPP__

#include <vector>
#include <string>
#define NULL_ITEM "-"
using namespace std;

class Recipe{
    private :
        int row;
        int column;
        string* blueprint;
        string itemName;
        int createdProduct;
    public :
        // Constructor
        Recipe();
        Recipe(int , int);
        ~Recipe();

        // Row Properties
        void setRow(int);
        int getRow() const;

        // Column Properties
        void setColumn(int);
        int getColumn() const;
        
        // Blueprint Properties
        void setBlueprint(int , string);
        string* getBlueprint();
        
        // Operator
        string operator[](int);

        // ItemName Properties
        void setItemName(string);
        string getItemName() const;

        // CreatedProduct Properties
        void setCreatedProduct(int);
        int getCreatedProduct() const;

};

#endif