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
		if (command == "EXPORT") {
			exportFile(inv);

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