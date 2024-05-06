

#include <iostream>
using namespace std;

string pivot;
int pindex;
void inputInArray(string  arr[],int n) {
	for (int i = 0;i < n;i++) {
		cout << "Enter the value of index no " << i << " : ";
		cin >> arr[i];
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
		cout << arr[i] << " ";
}
int main() {

	string files[6];
	inputInArray(files, 6);
	int lowerBound = 0;
	int upperBound = 5;
	int sizeOfArr = 6;
	quickSort(files, lowerBound, upperBound);
	printArray(files,sizeOfArr);
	return 0;
}