#include <iostream>
using namespace std;

struct Movie {
	string nameOfMovie;
	int numberOfTickets;
}movieObj[6];

void enQueue(Movie obj[], int maxsize, int& front, int& rear, string nameOfMovie,int numberOfTickets) {
	if (front == rear + 1 or (front == 0 and rear == maxsize))
		cout << "Queue is full" << endl;
	else {
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else if(rear == maxsize and front !=0)
			rear = 0;
		
		else 
			rear += 1;
		obj[rear].nameOfMovie = nameOfMovie;
		obj[rear].numberOfTickets = numberOfTickets;
	}
}
void deQueue(Movie obj[], int maxsize, int& front, int& rear) {
	if (front == -1)
		cout << "Queue is empty";
	else {
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else if (front == maxsize)
			front = 0;
		else
			front += 1;
	}
}
void displayQueue(Movie obj[],int&front,int&rear) {
	for (int i = front; i < rear; i++)
		cout << obj[i].nameOfMovie << " " << obj[i].numberOfTickets << endl;
}
int main() {

	
	int maxsize = 5;
	int front = -1;
	int rear = -1;

	enQueue(movieObj, maxsize, front, rear, "Avatar", 10);
	enQueue(movieObj, maxsize, front, rear, "Inception", 7);
	enQueue(movieObj, maxsize, front, rear, "Dark knight", 4);
	enQueue(movieObj, maxsize, front, rear, "Intersteller", 8);
	enQueue(movieObj, maxsize, front, rear, "The Matrix", 2);
	enQueue(movieObj, maxsize, front, rear, "Star wars", 15);

	displayQueue(movieObj,front,rear);

	enQueue(movieObj, maxsize, front, rear, "Divergent", 25);

	deQueue(movieObj,maxsize,front,rear);
	deQueue(movieObj, maxsize, front, rear);
	deQueue(movieObj, maxsize, front, rear);
	deQueue(movieObj, maxsize, front, rear);
	deQueue(movieObj, maxsize, front, rear);
	deQueue(movieObj, maxsize, front, rear);
	deQueue(movieObj, maxsize, front, rear);


	displayQueue(movieObj, front, rear);



	return 0;
}