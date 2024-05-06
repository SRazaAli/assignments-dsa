#include <iostream>
using namespace std;

int pindex,pivot;
int partition(int arr[], int lowerBound, int upperBound) {
		pivot = arr[upperBound];
		pindex = lowerBound;

	for (int i = lowerBound; i <upperBound; i++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[pindex]);
				pindex += 1;
		}
	}
	swap(arr[pindex], arr[upperBound]);
	return pindex;
}
void quickSort(int arr[], int lowerBound, int upperBound) {
	if (lowerBound < upperBound) {
		pindex = partition(arr, lowerBound, upperBound);
		quickSort(arr, lowerBound, pindex - 1);
		quickSort(arr, pindex+1, upperBound);
		}

	
}
void printArray(int arr[]) {
	for (int i = 0; i < 16; i++)
		cout << arr[i] << " ";
}
int main() {

	int ages[16] = { 21,19,22,18,17,23,15,25,19,14,23,21,13,16,20,17 };
	int lowerBound = 0;
	int upperBound = 15;

	quickSort(ages, lowerBound, upperBound);
	printArray(ages);
	return 0;
}