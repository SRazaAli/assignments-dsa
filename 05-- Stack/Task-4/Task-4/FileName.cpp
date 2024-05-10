#include <iostream>
#include <array>
using namespace std;

bool isEmpty( int& top) {
	if (top == -1)
		return true;
	else
		return false;
}
void push(char stack[], char item, int& top) {
	if (top == 4)
		cout << "Stack Overflow\n";
	else {
		top += 1;
		stack[top] = item;
	}
}
//masla
char pop(char stack[],  int& top) {
	if (isEmpty(top))
		cout << "Stack Underflow\n";
	else {
		char poppedElement = stack[top];
		top -= 1; 
		return poppedElement;
	}
}
void validatePostfix(char stack[],int&top) {
	for (int i = 0; i < 5; i++) {
		if (stack[i] == '+' or stack[i] == '-' or stack[i] == '*' or stack[i] == '/' or stack[i] == '^' or stack[i] == '%') {
			int a = pop(stack, top) - '0'; 
			int b = pop(stack, top) - '0';
			int c;
			if (stack[i] == '+')
				 c = b + a;
			else if (stack[i] == '-')
				 c = b - a;
			else if (stack[i] == '*')
				c = b * a;
			else if (stack[i] == '/')
				c = b / a;
			else if (stack[i] == '^')
				c = b ^ a;
			else if (stack[i] == '%')
				c = b % a;
			push(stack, c + '0', top);
		}
		else
			push(stack, stack[i], top);
	}
	if (top == 0) {
		cout << stack[top];
		cout << "Valid postfix expression...\n";
	}
	else {
		cout << "Invalid postfix expression...\n";
	}
}

void displayStack(char stack[], int& top) {
	for (int i = top; i >= 0; i--)
		cout << stack[i] << endl;
}
int main() {

	char expression[5] = {'2','3','*','3','+'};
	int top = -1;
	validatePostfix(expression, top);

	return 0;
}