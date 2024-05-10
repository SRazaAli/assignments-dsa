#include <iostream>
using namespace std;

void push(char stack[],char item,int&top) {
	if (top == 5)
		cout << "Stack Overflow\n";
	else {
		top += 1;
		stack[top] = item;
		cout << item << " has been pushed in stack\n";
	}
}
void pop(char stack[],  int& top) {
	if (top == -1)
		cout << "Stack Underflow\n";
	else {
		cout << stack[top] << " has been removed successfully\n";
		top -= 1;	
	}
}
void displayStack(char stack[], int& top) {
	for (int i = top; i >= 0; i--) {
		cout << stack[i] << endl;
	}
}
bool isEmpty(int&top) {
	if (top == -1)
		return true;
	else
		return false;
}
int main() {

	char arr[6] = {'{','[','(',')',']','}'};
	char stack[6];
	int top = -1;

	for (int i = 0; i < 6; i++) {
		if(arr[i]=='{' or arr[i]=='[' or arr[i]=='(')
			push(stack, arr[i], top);
	}
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if ((stack[i] == '(' and arr[j] == ')') or (stack[i] == '[' and arr[j] == ']') or (stack[i] == '{' and arr[j] == '}'))
				pop(stack, top);
		}
	}
	if (isEmpty(top))
		cout << "Equation is balanced\n";
	else
		cout << "Equation is imbalance";
	return 0;
}