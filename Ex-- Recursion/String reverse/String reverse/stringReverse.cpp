#include <iostream>
#include<stack>
using namespace std;

string stringReverseIterative(string str1, string str2) {
	for (int i = str1.length() - 1; i >= 0; i--)
		str2+= str1[i];
	return str2;
}
string stringReverseRecursive(string str1, string str2,int i) {
	if (i<0)
		return str2;
	else{
		str2 += str1[i];
		return stringReverseRecursive(str1, str2, i - 1);
	}
}
int main() {

	string str1 = "abcd";
	string str2;
	int i = str1.length() - 1;
	cout << stringReverseRecursive(str1, str2, i);
	return 0;
}