#include <iostream>
using namespace std;

int main() {

	int arr[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter the value of index : " << i << endl;
		cin >> arr[i];
	}
	cout << "Array before reversing : \n";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\t";
	cout << "\nArray after reversing : \n";
	for (int i = 9; i >= 0; i--)
		cout << arr[i] << "\t";
	return 0;
}