#include <iostream>
using namespace std;

struct hashTable {
	int key;
	string name;
};

const int tableSize = 11;
hashTable table[tableSize];

void initHashTable() {
	for (int i = 0; i < tableSize; i++) {
		table[i].key = -1;
	}
}

int hashFunction(int key) {
	return key % tableSize;
}

void insertRecord(int key,string name) {
	int keyIndex = hashFunction(key);
	if (table[keyIndex].key == -1) {
		table[keyIndex].key = key;
		table[keyIndex].name = name;
		cout << "key successfully inserted...\n";
	}
	else {
		int newKeyIndex = keyIndex;		//quadratic collision handling

		for (int i = 0; i < tableSize; i++) {
			if (table[newKeyIndex].key != -1) {
				newKeyIndex = (keyIndex + i * i) % tableSize;
			}
			else {
				break;
			}
		}
		if (table[newKeyIndex].key == -1) {
			table[newKeyIndex].key = key;
			table[newKeyIndex].name = name;
			cout << "Collision was handled successfully...\n";
		}
	}
}

void searchRecord(int key) {
	cout << "============ Search Key ============\n";
	int keyIndex = hashFunction(key);
	if (table[keyIndex].key != -1) {
		cout << "key : " << table[keyIndex].key << "\nname : " << table[keyIndex].name << "\n";
	}
	else {
		cout << "Record doesnt exist...\n";
	}
}

void deleteRecord(int key) {
	cout << "============ Delete Key ============\n";
	int keyIndex = hashFunction(key);
	if (table[keyIndex].key != -1) {
		table[keyIndex].key = -1;
		table[keyIndex].name = "";
		cout << "key was successfully deleted...\n";
	}
	else {
		cout << "There was an error deleting the key...\n";
	}
}

void displayHashTable() {
	cout << "============ Display Table ============\n";

	for (int i = 0; i < tableSize; i++) {
		cout << i << "  ------   " << table[i].key << "  " << table[i].name << " \n";
	}
}

int main() {

	initHashTable();
	displayHashTable();

	insertRecord(281, "raza");
	insertRecord(346, "aimen");
	insertRecord(823, "bilal");
	insertRecord(112, "muskan");
	insertRecord(234, "huzaifa");
	insertRecord(847, "ali");
	insertRecord(387, "sana");
	insertRecord(392, "sara");
	insertRecord(586, "alina");

	displayHashTable();

	searchRecord(112);
	displayHashTable();

	deleteRecord(281);
	displayHashTable();


	return 0;
}