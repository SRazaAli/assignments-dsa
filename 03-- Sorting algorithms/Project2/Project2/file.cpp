#include <iostream>
using namespace std;

int main() {

	float arr[34] = { 109,74, 49 ,103, 95 , 90, 118, 52, 104 , 88 , 101 , 96 , 72 , 56 , 64 , 110 ,97 , 77 , 59, 62 , 96 , 82, 65, 85 , 105, ,116 , 89, 91 , 83 , 99, 52, 76 , 84 };

	float temp, min;
	for (int i = 0; i < 34; i++) {
		min = arr[i];
		for (int j = 0; j < 33; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
			}
		}
	}
	cout << "[";
	for (int i = 0; i < 34; i++) {
		cout << arr[i] << " ";
	}
	cout << "]";


	return 0;
}