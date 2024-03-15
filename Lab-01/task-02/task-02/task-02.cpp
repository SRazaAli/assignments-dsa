#include <iostream>
#include <string>
using namespace std;

int main() {
	int position;
	string element;
	string arr[10] = { "Sara","Hamza","Musa","Haris","Amna","Mariam","Saad","Sameer","Talha"};
	cout << "Enter the position to insert a number \n";
	cin >> position;
	cout << "Enter the value to insert\n";
	cin >> element;
	int sizeOfArr = 8;
	for (int i = sizeOfArr; i >= position; i--) {
		arr[i + 1] = arr[i];
	}
	arr[position] = element;
	sizeOfArr += 1;
	for (int i = 0; i <= sizeOfArr; i++) {
		cout << arr[i] << "\t";
	}

	cout << "\nEnter the position to delete its value\n";
	
	cin >> position;
	for (int i = position; i < sizeOfArr; i++) {
		arr[i] = arr[i + 1];
	}
	sizeOfArr -= 1;
	for (int i = 0; i <= sizeOfArr; i++) {
		cout << arr[i] << "\t";
	}

	return 0;
}