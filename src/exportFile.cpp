#include "../include/Item.hpp"
#include "../include/Tool.hpp"
#include "../include/NonTool.hpp"
#include "../include/Container.hpp"
#include "../include/exportFile.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>


void exportFile(Container inv , string outputPath){
    ofstream outputFile(outputPath);

    for(int i = 0; i < 27; i++) {
        try{
            outputFile << inv.getItem(i).item->output(inv.getItem(i).qty);
        }catch(Exception& e){
            outputFile << "0:0";
        }

        if(i+1 != 27) {outputFile<<endl;}
    }
    outputFile.close();
    return;
}