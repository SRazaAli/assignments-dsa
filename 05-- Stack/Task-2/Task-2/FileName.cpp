#include <iostream>
using namespace std;

void draw(string stack[],int&top,int&player) {
	if (top == -1)
		cout << "No ball available for player " << player;
	else {
		cout << "Player " << player << " drew a " << stack[top] << " ball" << endl;
		top -= 1;	
		player += 1;
	}
}
int main() {
	string drawer[5] = { "Blue","Green","Red","Yellow","Orange" };
	int top = 4;
	int player = 1;
	cout << "Welcome to colorful ball drawing game...\n";
	draw(drawer, top, player);
	draw(drawer, top, player);
	draw(drawer, top, player);
	draw(drawer, top, player);
	draw(drawer, top, player);
	draw(drawer, top, player);




	return 0;
}