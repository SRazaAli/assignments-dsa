#include <iostream>
#include <string>
using namespace std;

int pindex;
string pivot;
void inputInArray(string arr[],int n) {
	for (int i = 0;i < n;i++) {
		cout << "Enter the value of index no " << i << " : ";
		getline(cin,arr[i]);
	}
}
int partition(string arr[], int lowerBound, int upperBound) {
	pivot = arr[upperBound];
	pindex = lowerBound;

	for (int i = lowerBound; i < upperBound; i++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[pindex]);
			pindex += 1;
		}
	}
	swap(arr[pindex], arr[upperBound]);
	return pindex;
}
void quickSort(string arr[], int lowerBound, int upperBound) {
	if (lowerBound < upperBound) {
		pindex = partition(arr, lowerBound, upperBound);
		quickSort(arr, lowerBound, pindex - 1);
		quickSort(arr, pindex + 1, upperBound);
	}


}
void printArray(string arr[],int n) {
	for (int i = 0; i < n; i++)
		cout <<i<< ". "<< arr[i] << endl;
}
int main() {

	string books[5];
	int lowerBound = 0;
	int upperBound = 4;
	inputInArray(books, 5);
	quickSort(books, lowerBound, upperBound);
	printArray(books,5);
	return 0;
}