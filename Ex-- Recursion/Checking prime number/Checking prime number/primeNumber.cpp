#include <iostream>
#include<stack>
using namespace std;

void prime(int n, int i, int remainder) {
	if (i < n and remainder == 0)
		cout << n << " is not prime\n";
	else if (i > n and remainder == 0)
		cout << n << " is prime \n";
	else {
		int remainder = n % i;
		return prime(n, i + 1, remainder);
	}
}

int main() {
	prime(7, 1, 1.5);


	return 0;
}