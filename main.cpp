//Implementasi Class
#include "include/Container.hpp"
#include "include/CraftingTable.hpp"
#include "include/Exception.hpp"
#include "include/exportFile.hpp"
#include "include/Item.hpp"
#include "include/NonTool.hpp"
#include "include/readFile.hpp"
#include "include/Recipe.hpp"
#include "include/Tool.hpp"

using namespace std;

void helpCommand(){
	cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
	cout << "  COMMAND       ||        FORMAT\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
	cout << "GIVE		|| GIVE [item name] [item quantity]" << endl;
	cout << "SHOW		|| SHOW" << endl;
	cout << "CRAFT		|| CRAFT" << endl;
	cout << "MOVE		|| MOVE [inventory's index (I0..I26)]       [item quantity]   [crafting table's index (C0..C8)]" << endl;
	cout << "MOVE		|| MOVE [crafting table's index (C0..C8)]   [item quantity]   [inventory's index (I0..I26)]" << endl;
	cout << "MOVE		|| MOVE [inventory's index (I0..I26)]       [item quantity]   [inventory's index (I0..I26)]" << endl;
	cout << "MOVE		|| MOVE [crafting table's index (C0..C8)]   [item quantity]   [crafting table's index (C0..C8)]" << endl;
	cout << "SWAP		|| SWAP [inventory's index (I0..I26)]       [crafting table's index (C0..C8)]" << endl;
	cout << "SWAP		|| SWAP [crafting table's index (C0..C8)]   [inventory's index (I0..I26)]" << endl;
	cout << "SWAP		|| SWAP [inventory's index (I0..I26)]       [inventory's index (I0..I26)]" << endl;
	cout << "SWAP		|| SWAP [crafting table's index (C0..C8)]   [crafting table's index (C0..C8)]" << endl;
	cout << "USE		|| USE [inventory's index (I0..I26)]" << endl;
	cout << "DISCARD	        || DISCARD [inventory's index (I0..I26)]     [item quantity]" << endl;
	cout << "DISCARD	        || DISCARD [crafting table's index (C0..C8)] [item quantity]" << endl;
	cout << "AVAILABLE	|| AVAILABLE" << endl;
	cout << "HELP		|| HELP" << endl;
	cout << "QUIT		|| QUIT" << endl;
	cout << "EXPORT		|| EXPORT [file name]" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------\n\n";
	return;
}

int main() {
	// INISIALISASI VARIABEL
	Container inv{27};
	CraftingTable craftingTable;

  	// READ ITEM
  	// readConfigItem return void variable untuk listItem telah diset di dalam readFile.cpp
  	// sehingga tidak perlu = dan create variable baru
  	readConfigItem();

  	/* READ RECIPES
  	   readConfigRecipes return void variable untuk recipes telah diset di dalam readFile.cpp
  	   sehingga tidak perlu = dan create variable baru */
	readConfigRecipes();

	// COMMAND
	string command;
	cout << "Command : ";
	while (cin >> command) {
		if (command == "EXPORT") {
			string outputPath;
    		cin >> outputPath;		// nama file
			exportFile(inv , outputPath);
			cout << "File successfully exported !!" << endl<< endl;
			
		} else if (command == "SHOW") {
			cout << "-------------------------------------------------------------------INVENTORY-------------------------------------------------------------------\n";
			inv.display();
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "\n";
			cout << "-----------------CRAFTING TABLE-----------------\n";
			craftingTable.display();
			cout << "------------------------------------------------\n";
		} else if (command == "CRAFT") {
			try{
				craftingTable.craft(inv);
				cout << "Item successfully crafted !!" << endl << endl;
			}catch(Exception &e){
				cout<<e.what();
			}
		} else if (command == "GIVE") {
			char itemName[100];
			char dummy[100];
			char Qty[100];
			string temp;
			cin.clear(); cin.ignore();
			getline(cin , temp);

			if (sscanf(temp.c_str() , "%s %s %s", itemName, Qty , dummy) > 2){
				cout << "Wrong input. Please try again.\n";
			} else {
				// digunakan untuk mencari index dari item yang diinginkan			
				int itemIndex = getIDfromName(itemName) - 1;

				if(itemIndex < 0) {
					cout << "Wrong item's name. Please try again.\n";
				}else {
					int itemQty = stoi(string(Qty)); 
					try{
						if(listItem[itemIndex]->getType() == ItemType::Tool) {
							for (int i=0; i<itemQty; i++) {
								inv.insert(*listItem[itemIndex], ((Tool*) listItem[itemIndex])->getDurability());
							}
						}
						else {
							inv.insert(itemQty, *listItem[itemIndex]);
						}
						cout << "Item successfully inserted !!" << endl<< endl;
					}catch(Exception &e){
						cout<<e.what();
					}
				}
			}
		} else if (command == "MOVE") {
			string slotSrc;
			int slotQty;
			vector<string> slotDest;
			cin >> slotSrc >> slotQty;

			string temp;
			getline(cin, temp);
			istringstream iss(temp);
			while (iss >> temp){
				slotDest.push_back(temp);
			}
			char slotSrcType;

			/*
			Untuk handle semisal tipenya berbeda => MOVE I1 5 I4 C5
			(Biar universal aja jadi gak perlu buat pengecekan supaya tipenya harus sama pas input MOVE)
			*/
			vector<char> slotDestType;

			int slotSrcIdx;
			vector<int> slotDestIdx;

			slotSrcType = slotSrc[0];
			for (int i=0; i<slotDest.size(); i++)
			{
				slotDestType.push_back(slotDest[i][0]);
			}
			
			// getting the slots index
			slotSrcIdx = stoi(slotSrc.substr(1, slotSrc.size() - 1));

			for (int i=0; i<slotDest.size(); i++){
				slotDestIdx.push_back(stoi(slotDest[i].substr(1, slotDest[i].size() - 1)));
			}

			// variable untuk asal container dan akhir container
			Container* source;
			Container* destination;

			// mengeset asal container
			if(slotSrcType == 'I') {
				source = &inv;
			} else {
				source = &craftingTable;
			}

			try{
				for (int i=0; i<slotDest.size(); i++)
				{
					if(slotDestType[i] == 'I') {
						destination = &inv;
					} else {
						destination = &craftingTable;
					}
					Container::move(*source, slotSrcIdx, *destination, slotDestIdx[i], slotQty);
				}
				cout << "Item successfully moved !!" << endl<< endl;
			}catch(Exception &e){
				cout<<e.what();
			}
		} else if(command == "USE") {
			string slot;
			cin >> slot;

			char slotType = slot[0];
			int slotIdx = stoi(slot.substr(1, slot.size() - 1));

			try{
				if(slotType == 'I') {		// USE IN INVENTORY
					Tool* temp = (Tool*) inv.getItem(slotIdx).item;
					if (temp->getType() != ItemType::Tool){
						cout<<"Can't use nontool item\n\n";
					}else{
						temp->use();
						if (temp->getDurability() == 0) inv.discard(slotIdx,1);
						cout << "Item successfully used !!" << endl << endl;
					}
				} else {					// USE IN CRAFTING TABLE
					cout << "Invalid position to use item\n\n";
				}
			}catch(Exception &e){
				cout<<e.what();
			}
			
		} else if(command == "DISCARD") {
			string slot;
			int qty;
			cin >> slot >> qty;

			char slotType = slot[0];
			int slotIdx = stoi(slot.substr(1, slot.size() - 1));

			try{
				if(slotType == 'I') {
					inv.discard(slotIdx, qty);
				} else {
					craftingTable.discard(slotIdx, qty);
				}
				cout << "Item successfully discarded !!" << endl<< endl;
			}catch(Exception &e){
				cout<<e.what();
			}
		} else if (command =="SWAP"){
			
			string Src, Dst;
			cin >> Src >> Dst;
			int srcIdx = stoi(Src.substr(1, Src.size() - 1));
			int dstIdx = stoi(Dst.substr(1, Dst.size() - 1));

			try {
				if (Src[0] == 'I' && Dst[0] == 'I') 		Container::swap(inv, srcIdx, inv, dstIdx);
				else if (Src[0] == 'I' && Dst[0] == 'C') 	Container::swap(inv, srcIdx, craftingTable, dstIdx);
				else if (Src[0] == 'C' && Dst[0] == 'I') 	Container::swap(craftingTable, srcIdx, inv, dstIdx);
				else if (Src[0] == 'C' && Dst[0] == 'C') 	Container::swap(craftingTable, srcIdx, craftingTable, dstIdx);

				cout << "Item successfully swapped !!" << endl<< endl;
			} catch(Exception &e) {
				cout<<e.what();
			}
		} else if (command == "AVAILABLE"){
			showAvailableItem();
		} else if (command == "HELP"){
			helpCommand();
		} else if (command == "QUIT"){
			string answer;
			cout << "You sure you want to quit ? (YES / NO)\n";
			cin >> answer;
			if(answer == "YES"){
				cout << "ok. terserahhhh :3" << endl;
				break;
			}else{
				cout << "fufufu, You better behave well, fufufu" << endl;
			}
		} else {
			cout << "INVALID COMMAND. PLEASE TRY AGAIN !!!" << endl << endl;
		}
		cout << "Command : ";
	}
}