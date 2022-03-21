#include <iostream>
#include "Reference.hpp"

int main() {
	//INISIALISASI VARIABEL GLOBAL
	Container inv{27};

	/**
	 * Variable ini untuk crafting table
	 */
	CraftingTable craftingTable;


  	/** READ ITEM
  	 * readConfigItem return void
  	 * variable untuk listItem telah
  	 * diset di dalam readFile.cpp
  	 * sehingga tidak perlu = 
  	 * dan create variable baru
  	 */
  	readConfigItem();

  	/** READ RECIPES
  	 * readConfigRecipes return void
  	 * variable untuk recipes telah
  	 * diset di dalam readFile.cpp
  	 * sehingga tidak perlu = dan create
  	 * variable baru
  	 */
	readConfigRecipes();



	//COMMAND
	string command;
	cout << "Command : ";
	while (cin >> command) {
		if (command == "EXPORT") {							// EXPORT FILE
			string outputPath;
    		cin >> outputPath;		//nama file
			exportFile(inv , outputPath);
			cout << "File successfully exported ❤️" << endl;
			
		} else if (command == "SHOW") {						// SHOW INVENTORY
			inv.display();
			craftingTable.display();
		} else if (command == "CRAFT") {					// CRAFT ITEM

			craftingTable.craft(inv);

		} else if (command == "GIVE") {						// GIVE ITEM
			string itemName;
			int itemQty;
			cin >> itemName >> itemQty;

			/**
			 * digunakan untuk mencari 
			 * index dari item
			 * yang diinginkan
			 */
			int itemIndex = -1;
			for(int i = 0; i < listItem.size(); ++i) {
				if(listItem[i]->getName() == itemName) {
					itemIndex = i;
					break;
				}
			}

			inv.insert(itemQty, *listItem[itemIndex]);
		} else if (command == "MOVE") {
			string slotSrc;
			int slotQty;
			string slotDest;
			// need to handle multiple destinations
			cin >> slotSrc >> slotQty >> slotDest;

			char slotSrcType;
			char slotDestType;
			int slotSrcIdx;
			int slotDestIdx;

			/**
			 * getting the slots type
			 */
			slotSrcType = slotSrc[0];
			slotDestType = slotDest[0];

			/**
			 * getting the slots index
			 */
			slotSrcIdx = stoi(slotSrc.substr(1, slotSrc.size() - 1));
			slotDestIdx = stoi(slotDest.substr(1, slotDest.size() - 1));

			/**
			 * variable untuk asal container
			 * dan akhir container
			 */
			Container* source;
			Container* destination;

			/**
			 * mengeset asal container
			 */
			if(slotSrcType == 'I') {
				source = &inv;
			} else {
				source = &craftingTable;
			}

			/**
			 * mengeset akhir container
			 */
			if(slotDestType == 'I') {
				// semua
				destination = &inv;
				Container::move(*source, slotSrcIdx, *destination, slotDestIdx);
			} else {
				// hanya sesuai input
				destination = &craftingTable;
				Container::move(*source, slotSrcIdx, *destination, slotDestIdx, slotQty);
			}

			//Container::move(*source, slotSrcIdx, *destination, slotDestIdx, slotQty);

		} else if(command == "USE") {
			string slot;
			cin >> slot;

			/**
			 * membuat variable untuk mendapatkan
			 * tipe dari slot
			 * dan index dari slot
			 */
			char slotType = slot[0];
			int slotIdx = stoi(slot.substr(1, slot.size() - 1));

			/**
			 * mengecek tipe dari slot
			 */
			if(slotType == 'I') {
				Tool* temp = (Tool*) inv.getItem(slotIdx).item;
				temp->use();
			} else {
				Tool* temp = (Tool*) craftingTable.getItem(slotIdx).item;
				temp->use();
			}
		} else if(command == "DISCARD") {
			string slot;
			int qty;
			cin >> slot >> qty;

			/**
			 * membuat variable untuk mendapatkan
			 * tipe dari slot
			 * dan index dari slot
			 */
			char slotType = slot[0];
			int slotIdx = stoi(slot.substr(1, slot.size() - 1));

			/**
			 * mengecek tipe dari slot
			 */

			if(slotType == 'I') {
				inv.discard(slotIdx, qty);
			} else {
				craftingTable.discard(slotIdx, qty);
			}
		} else if(command == "AVAILABLE ITEM"){
			showAvailableItem();
		}
		} else {
			// todo
			cout << "Invalid command" << endl;
		}
		cout << "Command : ";
	}
}