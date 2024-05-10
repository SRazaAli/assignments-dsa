#include <iostream>
using namespace std;

int main() {

	int arr[10];
	int youngest,birthYear,pos;
	for (int i = 0; i < 10; i++) {
		cout << "Enter the birth year of student : " << i + 1 << endl;
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {
		birthYear = 2024 - arr[i];
		if (i == 0) 
			youngest = birthYear;
		
		if (birthYear < youngest) {
			youngest = birthYear;
			pos = arr[i];
		}
	}
	cout << "Youngest child : " << pos << endl;
	return 0;
}
