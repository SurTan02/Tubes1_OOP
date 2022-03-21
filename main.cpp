#include "Reference.hpp"

using namespace std;

int main() {
	//INISIALISASI VARIABEL GLOBAL
	Container inv(27);


  	// READ ITEM
	vector <Item*> listItem = readConfigItem();

	// READ RECIPES
	recipes = readConfigRecipes();



	//COMMAND
	string command;
	cout << "Command : ";
	while (cin >> command) {
		if (command == "SHOW"){
			inv.display();
		} else if (command == "EXPORT") {
			exportFile(inv);
			cout << "Exported" << endl;
			
		} else if (command == "CRAFT") {
			cout << "TODO" << endl;

		} else if (command == "GIVE") {
			string itemName;
			int itemQty;
			cin >> itemName >> itemQty;
			cout << "give done" << endl;

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
Show : tampilan
Give : Menambahkan Item ke Inventory.
Discard : Membuang item di slot inventory dengan kuantitas yang diberikan.
Move : Memindahkan Item ke slot crafting    |    Menumpuk Item.   |   Mengembalikan Item dari slot crafting ke inventory.
Use : Menggunakan Item.
Craft : Craft Item.
Export : Export Inventor