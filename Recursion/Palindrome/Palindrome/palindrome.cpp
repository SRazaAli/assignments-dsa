#include <iostream>
#include<stack>
using namespace std;

string stringReverseIterative(string str1, string str2) {
	for (int i = str1.length() - 1; i >= 0; i--)
		str2 += str1[i];
	return str2;
}
bool stringReverseRecursive(string str1, string str2, int i) {
	if (i < 0 and (str1 == str2))
		return true;
	else if (i < 0 and (str1 != str2))
		return false;
	else {
		str2 += str1[i];
		return stringReverseRecursive(str1, str2, i - 1);
	}
}
int main() {

	string str1 = "madam";
	string str2;
	int i = str1.length() - 1;
	if (!stringReverseRecursive(str1, str2, i))
		cout << str1 << " is not a palindrome" << endl;
	else
		cout << str1 << " is a palindrome" << endl;

	return 0;
}