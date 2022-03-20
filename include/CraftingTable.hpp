#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <array>
#include <vector>
#include <iterator>
#include <sstream>

#include "Container.hpp"
#include "Recipe.hpp"
#include "readFile.hpp"
#include "Exception.hpp"

class CraftingTable : public Container 
{
    private:

    public:
        CraftingTable(); 
        string getName(int n);
        bool isEmpty();
        bool isTool();
        bool isNonTool();
        bool check(string*);
        bool checkMirror(string*);
        bool checkSub(string*, int, int);
        void craft(Container&);
};

#endif