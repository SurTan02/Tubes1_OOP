#include "Reference.hpp"

using namespace std;

int main() {

  	// READ ITEM
	listItem = readConfigItem();

	// READ RECIPES
	recipes = readConfigRecipes();


	//INISIALISASI VARIABEL GLOBAL
	// Inventory inv;

	//COMMAND
	string command;
	cout << "Command : ";
	while (cin >> command) {
		if (command == "EXPORT") {
			string outputPath;
			cin >> outputPath;		//nama file
			ofstream outputFile(outputPath);

			// std::unique_ptr<Item> temp;
			// for(int i = 0; i < 27; i++) {
			// 	// temp = inv.getItem();
			// 	if(inv.getItem().Item::getType() == ItemType::Tool) {
			// 		outputFile << inv.getItem().getID() << ":" << inv.getItem().getDurability();
			// 	} else if(inv.getItem().getQuantity() > 0) {
			// 		outputFile < inv.getItem().getID() << ":" << inv.getItem().getQuantity();
			// 	} else {
			// 		outputFile << "0:0";
			// 	}
			// 	if(i+1 != 27) {outputFile<<endl;}
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