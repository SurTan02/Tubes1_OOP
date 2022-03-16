#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <dirent.h>
#include <list>
using namespace std;


// void printWords(string str)
// {
// 	// word variable to store word
// 	string word1 , word2 , word3;

// 	// making a string stream
// 	stringstream iss(str);

// 	// Read and print each word.
//     iss >> word1 >> word2 >> word3;
// 	cout << word1 << " hi1" << endl;
// 	cout << word2 << " hi2"<< endl;
// 	cout << word3 << " hi3"<< endl;
// }

// // Driver code
// int main()
// {
// 	string s = "sky is blue";
// 	printWords(s);
// 	return 0;
// }

#include <stdio.h>
#include <dirent.h>
using namespace std;

int main(void) {
	string configPath = "./config";
	string itemConfigPath = configPath + "/item.txt";
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("config/recipe/")) != NULL) {
        /* print all the files and directories within directory */
        int n = 2;
        while ((ent = readdir (dir)) != NULL) {
            if(n != 0){
                n--;
            }else{
                ifstream itemConfigFile(configPath + "/recipe/" + ent->d_name);
                for (string line; getline(itemConfigFile, line);) {
                    //get data
                    cout<<line<<endl;
                }
            }
        }
        closedir (dir);
     } else {
        /* could not open directory */
        perror ("");
        return -1;
     }

     return 0;
}