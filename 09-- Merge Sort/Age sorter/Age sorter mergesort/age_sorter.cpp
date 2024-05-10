/*You are the lead organizer of a prestigious summer camp for young scholars bringing their unique talents and
aspirations to create a vibrant and diverse community eager to learn and grow together.As part of the 
registration process, you've been tasked with sorting a list of students based on their ages, from youngest to 
oldest using merge sort. */


#include <iostream>
using namespace std;


void merge(int arr[], int lowerBound, int upperBound, int mid) {
	int i, j, k, auxilarly[16];
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

void mergeSort(int arr[], int lowerBound, int upperBound) {
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
void printArray(int arr[],int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main() {

	int ages[16] = { 21,19,22,18,17,23,15,25,19,14,23,21,13,16,20,17 };
	int lowerBound = 0;
	int upperBound = 15;

	mergeSort(ages, lowerBound, upperBound);
	printArray(ages, 16);

	return 0;
}