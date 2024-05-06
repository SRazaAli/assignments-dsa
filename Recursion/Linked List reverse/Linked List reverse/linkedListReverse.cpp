#include <iostream>
#include<stack>
using namespace std;

struct node {
	int data;
	node* next;
};
node* head = NULL;

void createNode(node*& head,int val) {
	if (head == NULL) {
		node* n = new node();
		n->data = val;
		n->next = NULL;
		head = n;
	}
}
void insertAtEnd(node*& head, int val) {
	if (head != NULL) {
		node* n = new node();
		n->data = val;
		n->next = NULL;
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
}
void displayList(node*& head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL";
}
void reverseList(node*& head) {
	node* temp = head;
	node* next = NULL;
	node* prev = NULL;
	while (temp!= NULL) {
		
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
	
}
int main() {
	createNode(head, 1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
	displayList(head);
	reverseList(head);
	cout << endl;
	displayList(head);


	return 0;
}