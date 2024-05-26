#include <iostream>
using namespace std;

struct hashTable {
	string countryName;
	string capital;
};

const int tableSize = 14;
hashTable table[tableSize];

void initHashTable() {
	for (int i = 0; i < tableSize; i++) {
		table[i].countryName = "";
	}
}

int hashFunction(string countryName) {
	return size(countryName) % tableSize;
}

void insertRecord(string countryName,string capital) {
	int keyIndex = hashFunction(countryName);
	
	if (table[keyIndex].countryName == "") {
		table[keyIndex].countryName = countryName;
		table[keyIndex].capital = capital;
		cout << "Record was inserted successfully...\n";
	}
	else {
		for (int i = 0; i < tableSize; i++) {
			if (table[keyIndex].countryName != "") {
				keyIndex = (keyIndex + 1) % tableSize;
			}
		}
		table[keyIndex].countryName = countryName;
		table[keyIndex].capital = capital;
		cout << "collision was handled through linear probing...\n";
	}
}
void searchRecord(string countryName) {
	int keyIndex = hashFunction(countryName);
	if(countryName == table[keyIndex].countryName and table[keyIndex].countryName!="")
	cout << "Country name : " << table[keyIndex].countryName<<"\nCapital : "<<table[keyIndex].capital<<"\n";
}
void deleteRecord(string countryName) {
	int keyIndex = hashFunction(countryName);
	if (countryName == table[keyIndex].countryName and table[keyIndex].countryName != "") {
		table[keyIndex].countryName = "";
		table[keyIndex].capital= "";
		cout << "Record has been successfully deleted...\n";
	}
}
void updateRecord(string countryName,string newCapital) {
	int keyIndex = hashFunction(countryName);
	if (countryName == table[keyIndex].countryName and table[keyIndex].countryName != "") {
		table[keyIndex].capital = newCapital;
		cout << "Capital has been successfully updated...\n";
	}
}
void displayHashTable() {
	for (int i = 0; i < tableSize; i++) {
		cout << i << "  ------  " << table[i].countryName << "    " << table[i].capital << "\n";
	}
}

int main() {

	initHashTable();
	insertRecord("United States","Washington DC");
	insertRecord("Brazil", "Brasilia");
	insertRecord("Japan", "Tokyo");
	insertRecord("Germany", "Berlin");
	insertRecord("Pakistan", "Islamabad");
	insertRecord("Argentina", "Buenos");
	insertRecord("Australia", "Canberra");

	displayHashTable();
	cout << "====== Search Record ======\n";
	searchRecord("United States");
	searchRecord("Pakistan");
	cout << "====== Delete Record ======\n";
	searchRecord("Japan");
	searchRecord("Argentina");
	cout << "====== Update Record ======\n";
	updateRecord("Pakistan","Karachi");

	displayHashTable();
	return 0;
}
