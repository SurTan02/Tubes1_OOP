// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "Reference.cpp"

using namespace std;

int main() {
	string configPath = "./config";
	string itemConfigPath = configPath + "/item.txt";

  	// read item from config file
  	// ifstream itemConfigFile(itemConfigPath);
  	// for (string line; getline(itemConfigFile, line);) {
	// 	cout << line << endl;
	// 	// do something
  	// }

	// // read recipes
	// for (const auto &entry :
	// 	filesystem::directory_iterator(configPath + "/recipe")) {
	// 	cout << entry.path() << endl;
	// 	// read from file and do something
	// }

	//INISIALISASI VARIABEL GLOBAL
	Inventory inv;

	//COMMAND
	string command;
	cout << "Command : ";
	while (cin >> command) {
		if (command == "EXPORT") {
			string outputPath;
			cin >> outputPath;		//nama file
			ofstream outputFile(outputPath);

			Item temp;
			for(int i = 0 ; i < 27 ; i++){
				temp = inv.getItem(i);
				if(temp.getType() == "Tool"){		// Tool
					outputFile << temp.getID() << ":" << temp.getDurability() << endl;
				}else if(temp.getQuantity() > 0){	// Non Tool
					outputFile << temp.getID() << ":" << temp.getQuantity() << endl;
				}else{								// Tidak ada Item
					outputFile << "0:0" << endl;
				}
			}
			// // hardcode for first test case
			// outputFile << "21:10" << endl;
			// outputFile << "6:1" << endl;
			// for (int i = 2; i < 27; i++) {
			// 	outputFile << "0:0" << endl;
			// }
			cout << "Exported" << endl;
			
		} else if (command == "CRAFT") {
			cout << "TODO" << endl;

		} else if (command == "GIVE") {
			string itemName;
			int itemQty;
			cin >> itemName >> itemQty;
			cout << "TODO" << endl;

		} else if (command == "MOVE") {
			string slotSrc;
			int slotQty;
			string slotDest;
			// need to handle multiple destinations
			cin >> slotSrc >> slotQty >> slotDest;
			cout << "TODO" << endl;

		} else {
			// todo
			cout << "Invalid command" << endl;
		}
		cout << "Command : ";
	}
  return 0;
}
