#include <iostream>
using namespace std;


void merge(float arr[], int lowerBound, int upperBound, int mid) {
	int i, j, k;
	float  auxilarly[16];
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

void mergeSort(float arr[], int lowerBound, int upperBound) {
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
void printArray(float arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}
int main() {

	float ages[14] = { 5.6,6.0,5.11,5.9,5.8,5.7,6.1,5.5,5.4,5.3,6.2,5.2,5.0,4.90 };
	int lowerBound = 0;
	int upperBound = 13;

	mergeSort(ages, lowerBound, upperBound);
	printArray(ages, 13);

	return 0;
}