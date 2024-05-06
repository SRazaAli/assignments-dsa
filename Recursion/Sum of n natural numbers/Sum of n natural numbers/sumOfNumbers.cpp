#include <iostream>
#include<stack>
using namespace std;

int sumOfNumbers(int n) {
	if (n == 0)
		return n;
	else
		return sumOfNumbers(n - 1) + n;
}

int main() {
	int n = 8;
	sumOfNumbers(n);

	return 0;
}