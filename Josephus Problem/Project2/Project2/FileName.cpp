#include <iostream>
using namespace std;

 int N = 5;
int M = 1;

struct player {
	string playerName;
	player* next;
};
player* head = NULL;

void firstPlayer(player*& head, string playerName) {
	if (head == NULL) {
		player* p = new player();
		p->playerName = playerName;
		p->next = NULL;
		head = p;
	}
}
void insertNewPlayer(player*& head, string playerName) {
	player* p = new player();
	p->playerName = playerName;
	p->next = NULL;
	player* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = p;
}
void deleteFromStart(player*& head) {
	player* temp = head;
	head = head->next;
	delete temp;
}
//void deleteAtNthPosition(player*& head, int pos) {
//	player* temp = head;
//	player* temp1;
//	if (pos == 1)
//		deleteFromStart(head);
//	else {
//		for (int i = 1; i < pos - 1; i++) {
//			if (temp == NULL) {
//				temp = head;
//			}
//			else
//				temp = temp->next;
//			
//		}
//		
//			temp1 = temp->next;
//			temp->next = temp1->next;
//			delete temp1;
//		}
//	}
void deleteAtNthPosition(player*& head, int pos) {
	player* temp = head;
	player* temp1;
	if (pos == 1) {
		// If the first item itself needs to be deleted
		if (temp->next == nullptr) {
			// If there is only one item in the list, delete it and make the list empty
			delete temp;
			head = nullptr;
		}
		else {
			// If there are more than one items in the list, make the first item point to the next item and delete the second item
			temp1 = temp->next;
			head = temp1;
			delete temp;
		}
	}
	else {
		int count = 1;
		while (temp->next != nullptr) {
			count++;
			temp = temp->next;
		}
		if (pos > count) {
			// If the given position is beyond the list, make the last item the first item
			temp1 = head;
			for (int i = 1; i < count - 1; i++) {
				temp1 = temp1->next;
			}
			temp->next = head;
			head = temp;
			temp1->next = nullptr;
			temp1 = temp;
			temp = temp->next;
			delete temp;
			head = temp1;
		}
		else {
			temp = head;
			for (int i = 1; i < pos - 1; i++) {
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = temp1->next;
			delete temp1;
		}
	}
}
void displayPlayers(player*& head) {
	player* temp = head;
	while (temp != NULL) {
		cout << temp->playerName << " ";
		temp = temp->next;
	}
}
void playerEntries() {
	string playerName;
	for (int i = 0; i < N; i++) {
		cout << "Enter player name to add in the list : ";
		cin >> playerName;
		if (head == NULL)
			firstPlayer(head, playerName);
		else
			insertNewPlayer(head, playerName);
	}
}


int main() {
	playerEntries();

	while (N > 1) {
		deleteAtNthPosition(head, M);
		N--;
		M++;
		displayPlayers(head);
		cout << '\n';
	}
	displayPlayers(head);
	cout << " is the winner...";
	return 0;
}