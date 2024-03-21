#include <iostream>
using namespace std;


void enQue(int queue[],int maxsize,int&front,int&rear,int item) {
	if (rear == maxsize)
		cout << "Queue is Full" << endl;
	else {
		if (front == -1)
			front = 0;
		rear = rear + 1;
		queue[rear] = item;
	}
}
void deQue( int& front, int& rear) {
	if (front == -1 or front == rear + 1)
		cout << "Queue is empty" << endl;
	else
		front += 1;
}
void displayQueue(int queue[],int&front,int&rear) {
	for (int i = front; i <= rear; i++)
		cout << queue[i] << " ";
}

int main() {

	int myQueue[6];
	int maxsize = 5;
	int front = -1;
	int rear = -1;

	enQue(myQueue, maxsize, front, rear, 10);
	enQue(myQueue, maxsize, front, rear, 7);
	enQue(myQueue, maxsize, front, rear, 4);
	enQue(myQueue, maxsize, front, rear, 8);
	enQue(myQueue, maxsize, front, rear, 2);

	displayQueue(myQueue,front,rear);

	enQue(myQueue, maxsize, front, rear, 25);
	deQue(front,rear);
	deQue(front, rear);
	displayQueue(myQueue, front, rear);

	return 0;
}