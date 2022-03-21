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
			cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
			inv.display();
			cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\n";
			cout << "---------------------------------------------\n";
			craftingTable.display();
			cout << "---------------------------------------------\n";
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

			try{
				if(listItem[itemIndex]->getType() == ItemType::Tool)
				{
					for (int i=0; i<itemQty; i++)
					{
						inv.insert(*listItem[itemIndex], ((Tool*) listItem[itemIndex])->getDurability());
					}
				}
				else
				{
					inv.insert(itemQty, *listItem[itemIndex]);
				}
			}catch (Exception &e){
				e.what();
			}
		} else if (command == "MOVE") {
			string slotSrc;
			int slotQty;
			vector<string> slotDest;
			// need to handle multiple destinations
			cin >> slotSrc >> slotQty;

			string temp;
			getline(cin, temp);
			istringstream iss(temp);
			//cout << "in\n";
			while (iss >> temp)
			{
				slotDest.push_back(temp);
			}
			//cout << "out\n";

			char slotSrcType;

			/*
			Untuk handle semisal tipenya berbeda => MOVE I1 5 I4 C5
			(Biar universal aja jadi gak perlu buat pengecekan supaya tipenya harus sama pas input MOVE)
			*/
			vector<char> slotDestType;

			int slotSrcIdx;
			vector<int> slotDestIdx;

			/**
			 * getting the slots type
			*/

			//cout << "numero uno\n";
			slotSrcType = slotSrc[0];
			for (int i=0; i<slotDest.size(); i++)
			{
				slotDestType.push_back(slotDest[i][0]);
				//cout << i;
			}
			//cout << "\ndone\n";
			
			/**
			 * getting the slots index
			 */
			slotSrcIdx = stoi(slotSrc.substr(1, slotSrc.size() - 1));

			//cout << "numero duo\n";
			for (int i=0; i<slotDest.size(); i++)
			{
				slotDestIdx.push_back(stoi(slotDest[i].substr(1, slotDest[i].size() - 1)));
				//cout << i;
			}
			//cout << "\ndone\n";

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

			//cout << "numero trio\n";
			for (int i=0; i<slotDest.size(); i++)
			{
				if(slotDestType[i] == 'I') {
					destination = &inv;
				} else {
					destination = &craftingTable;
				}

				Container::move(*source, slotSrcIdx, *destination, slotDestIdx[i], slotQty);
				//cout << i;
			}
			//cout << "\ndone\n";


			/**
			 * mengeset akhir container
			 */
			// if(slotDestType == 'I') {
			// 	destination = &inv;
			// } else {
			// 	destination = &craftingTable;
			// }

			// Container::move(*source, slotSrcIdx, *destination, slotDestIdx, slotQty);

			/* UPDATE MOVE
			MOVE I1 5 I2
			Move I1 to I2 sebanyak 5

			MOVE I1 5 I2 I3
			Move I1 to I2 sebanyak 5
			Move I1 to I3 sebanyak 5
			*/

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
		} else if(command == "AVAILABLE"){
			showAvailableItem();
		} else {
			// todo
			cout << "Invalid command" << endl;
		}
		cout << "Command : ";
	}
}