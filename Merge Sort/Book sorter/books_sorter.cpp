#include <iostream>
#include <string>
using namespace std;

void inputInArray(string arr[], int n) {
	for (int i = 0;i < n;i++) {
		cout << "Enter the value of index no " << i << " : ";
		getline(cin, arr[i]);
	}
}
void merge(string arr[], int lowerBound, int upperBound, int mid) {
	int i, j, k;
	string auxilarly[16];
	i = lowerBound;
	j = mid + 1;
	k = lowerBound;

	while (i <= mid and j <= upperBound) {
		if (arr[i] < arr[j]) {				//sorting the first half
			auxilarly[k] = arr[i];
			k++;
			i++;
		}
		else {
			auxilarly[k] = arr[j];			//sorting the second half
			k++;
			j++;
		}
	}

	while (i <= mid) {						//if right arr is exhausted
		auxilarly[k] = arr[i];
		k++;
		i++;
	}
	while (j <= upperBound) {				//if left arr is exhausted
		auxilarly[k] = arr[j];
		k++;
		j++;
	}

	for (int i = lowerBound; i < k; i++) {	//copying sorted arr into org arr
		arr[i] = auxilarly[i];
	}
}

void mergeSort(string arr[], int lowerBound, int upperBound) {
	int mid;
	if (lowerBound < upperBound) {
		//dividing the array
		mid = (lowerBound + upperBound) / 2;
		mergeSort(arr, lowerBound, mid);
		mergeSort(arr, mid + 1, upperBound);
		//merging the array
		merge(arr, lowerBound, upperBound, mid);
	}
}
void printArray(string arr[], int n) {
	for (int i = 0; i < n; i++)
		cout <<i+1<<". "<< arr[i] << endl;
}
int main() {

	string books[5];
	int lowerBound = 0;
	int upperBound = 4;
	
	inputInArray(books, 5);
	mergeSort(books, lowerBound, upperBound);
	printArray(books, 5);

	return 0;
}