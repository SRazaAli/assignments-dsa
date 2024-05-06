#include <iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> stack1, stack<int> stack2) {
	if (stack2.size() == 4) {
		cout << "===== stack2 =====\n";
		while (!stack2.empty()) {
			cout << stack2.top() << "\n";
			stack2.pop();
		}
	}
	else {
		stack2.push(stack1.top());
		stack1.pop();
		reverseStack(stack1, stack2);
		;
	}
}

int main() {

	stack<int> stack1;
	stack1.push(4);
	stack1.push(3);
	stack1.push(2);
	stack1.push(1);
	stack<int> stack2;

	reverseStack(stack1, stack2);

	return 0;
}