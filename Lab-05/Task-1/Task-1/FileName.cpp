#include <iostream>
using namespace std;

bool isEmpty(int&top) {
	if (top == 6)
		return true;
	else
		return false;
}
void push(string stack[],string item, int& top) {
	if (isEmpty(top)) 
		cout << "Stack Overflow\n";
	else {
		top =top+ 1;
		stack[top] = item;
	}
}
void pop(int&top) {
	if (top == -1)
		cout << "Stack underflow";
	else
		top = top - 1;
}
void displayStack(string stack[],int&top) {
	for (int i = top; i >= 0; i--) {
		cout << stack[i] << endl;
	}
}

int main() {

	string stack[7];
	int top = -1;

	cout << "Entering books and printing stack\n";
	push(stack, "Harry Potter", top);
	push(stack, "To Kill a mocking bird", top);
	push(stack, "The Great Gatsby", top);
	push(stack, "1984", top);
	push(stack, "The Catcher in the Rye", top);
	push(stack, "Pride and Prejudice", top);
	push(stack, "The Hobbit", top);
	push(stack, "Lord of the rings", top);
	displayStack(stack,top);
	cout << "Removing an item and printing stack\n";
	pop(top);
	displayStack(stack, top);

	




	return 0;
}