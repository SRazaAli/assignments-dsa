#include <iostream>
using namespace std;

int main() {
	
	int books[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			cout << "Enter the year\n";
			cin >> books[i][j];
		}
		for (int j = 1; j < 2; j++) {
			cout << "Enter the no of books sold\n";
			cin >> books[i][j];
		}
	}
	int colOfUnits = 1;
	for (int i = 0; i < 3; i++) {
		if (books[i][colOfUnits] > 300) {
			for (int j = 0; j < 1; j++)
				cout << "Year : " << books[i][j] << "\n";
			for (int j = 1; j < 2; j++)
				cout << "Books sold : " << books[i][j] << "\n";
		}
	}
	return 0;
}