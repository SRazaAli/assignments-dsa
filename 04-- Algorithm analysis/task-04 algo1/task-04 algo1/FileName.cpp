#include <iostream>
#include <chrono>
using namespace std;

int main() {
	int n1 = 11;
	int n2 = 101;
	int n3 = 1111;
	int n4 = 1000003;
	int n5 = 10000000019;

	clock_t c_start1, c_end1;
	c_start1 = clock();
	bool isPrime1 = true;
	for (int i = 2; i < n1; i++) {
		if (n1 % i == 0)
			isPrime1 = false;
	}
	if (isPrime1)
		cout << n1 << " is a prime number";
	c_end1 = clock();

	double time1 = (double)(c_end1 - c_start1) / (double)CLOCKS_PER_SEC;
	cout << "\nTime for 11 = " << time1 << " sec " << endl;

	clock_t c_start2, c_end2;
	c_start2 = clock();
	bool isPrime2 = true;
	for (int i = 2; i < n2; i++) {
		if (n2 % i == 0)
			isPrime2 = false;
	}
	if (isPrime2)
		cout << n2 << " is a prime number";
	c_end2 = clock();

	double time2 = (double)(c_end2 - c_start2) / (double)CLOCKS_PER_SEC;
	cout << "\nTime for 101 = " << time2 << " sec " << endl;
	


	clock_t c_start3, c_end3;
	c_start3 = clock();
	bool isPrime3 = true;
	for (int i = 3; i < n3; i++) {
		if (n3 % i == 0)
			isPrime3 = false;
	}
	if (isPrime3)
		cout << n3 << " is a prime number";
	else
		cout << n3 << " is not a prime number";
	c_end3 = clock();

	double time3 = (double)(c_end3 - c_start3) / (double)CLOCKS_PER_SEC;
	cout << "\nTime for 1111 = " << time3 << " sec " << endl;



	clock_t c_start4, c_end4;
	c_start4 = clock();
	bool isPrime4 = true;
	for (int i = 4; i < n4; i++) {
		if (n4 % i == 0)
			isPrime4 = false;
	}
	if (isPrime4)
		cout << n4 << " is a prime number";
	c_end4 = clock();

	double time4 = (double)(c_end4 - c_start4) / (double)CLOCKS_PER_SEC;
	cout << "\nTime for 1000003 = " << time4 << " sec " << endl;

	clock_t c_start5, c_end5;
	c_start5 = clock();
	bool isPrime5 = true;
	for (int i = 5; i < n5; i++) {
		if (n5 % i == 0)
			isPrime5 = false;
	}
	if (isPrime5)
		cout << n5 << " is a prime number";
	else
		cout << n5 << " is not a prime number";
	c_end5 = clock();

	double time5 = (double)(c_end5 - c_start5) / (double)CLOCKS_PER_SEC;
	cout << "\nTime for 10000000019 = " << time5 << " sec " << endl;
	
	return 0;
}