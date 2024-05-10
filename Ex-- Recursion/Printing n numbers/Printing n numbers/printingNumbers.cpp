#include <iostream>
#include<stack>
using namespace std;

void naturalNumbers(int n) {
	if (n > 50)
		return;
	else {
		cout << n << " ";
		naturalNumbers(n + 1);
	}
}
int main() {
	
	int n = 1;
	naturalNumbers(n);

	return 0;
}