#include <string>
#include <list>
#include <iostream>
#include <filesystem>
#include <sstream>
using namespace std;


void printWords(string str)
{
	// word variable to store word
	string word1 , word2 , word3;

	// making a string stream
	stringstream iss(str);

	// Read and print each word.
    iss >> word1 >> word2 >> word3;
	cout << word1 << " hi1" << endl;
	cout << word2 << " hi2"<< endl;
	cout << word3 << " hi3"<< endl;
}

// Driver code
int main()
{
	string s = "sky is blue";
	printWords(s);
	return 0;
}
