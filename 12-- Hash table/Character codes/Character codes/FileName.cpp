#include <iostream>
using namespace std;

struct inputData {
	char character;
	int code;
	
};
inputData dataSet[26];

struct hashTable {
	string key;
	int code;
	
};

const int tableSize = 11;
hashTable table[tableSize];

//For Dataset
void initDataset() {
	char character = 'A';
	int code = 1;

	for (int i = 0; i < 26; i++) {
		dataSet[i].character = character;
		dataSet[i].code = code;
		character += 1;
		code += 1;
	}
}
void printDataset() {
	for (int i = 0; i < 26; i++) {
		cout << i << "  ------  " << dataSet[i].character << "  " << dataSet[i].code << "\n";
	}
}

//For hashTable
void initHashTable(){
	for (int i = 0; i < tableSize; i++) {
		table[i].key = "";
	}
}

int  hashFunction(string identifier) {
	char c1 = identifier[0];
	char c2 = identifier[size(identifier) - 1];
	int code1 = 0;
	int code2 = 0;
	for (int i = 0; i < tableSize; i++) {
		if (c1 == dataSet[i].character) {
			code1 = dataSet[i].code;
		}
		else if (c2 == dataSet[i].character) {
			code2 = dataSet[i].code;
		}
	}
	int average = (code1+ code2) / 2;
	return average % tableSize;
}

void insertRecord(string identifier) {
	int keyIndex = hashFunction(identifier);

	if (table[keyIndex].key == "") {
		table[keyIndex].key = identifier;
		cout << "Record was inserted successfully...\n";
	}
	else {
		for (int i = 0; i < tableSize; i++) {
			if (table[keyIndex].key != "") {
				keyIndex = (keyIndex + 1) % tableSize;
			}
		}
		table[keyIndex].key = identifier;
		cout << "Collision was handled through linear probing...\n";
	}
}
void printHashtable(){
	for (int i = 0; i < tableSize; i++) {
		cout << i << "  ------  " << table[i].key<< "\n";
	}
}

int main() {
	
	initDataset();
	printDataset();
	initHashTable();
	insertRecord("BETA");
	insertRecord("RATE");
	insertRecord("FREQ");
	insertRecord("ALPHA");
	insertRecord("MEAN");
	insertRecord("SUM");
	insertRecord("NUM");
	insertRecord("BAR");
	insertRecord("WAGE");
	insertRecord("PAY");
	insertRecord("KAPPA");
	printHashtable();

	return 0;
}