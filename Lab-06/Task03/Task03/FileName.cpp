#include<iostream>
using namespace std;

const int maxSize = 6;
int Queue[maxSize];
int F = -1, R = -1;

void enQueue(int item) {
    if (R == maxSize - 1) {
        cout << "Queue is full" << endl;
    }
    else {
        if (F == -1)
            F = 0;
        R++;
        Queue[R] = item;
    }
}

void deQueue() {
    if (F == -1 || F > R) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Dequeued element: " << Queue[F] << endl;
        F++;
    }
}

void display() {
    cout << "Items Stored In Queue: ";
    for (int i = F; i <= R; i++) {
        cout << Queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enQueue(101);
    enQueue(102);
    enQueue(103);

    deQueue();
    enQueue(104);

    deQueue();
    enQueue(105);

    deQueue();
    deQueue();
    deQueue();
    deQueue();

    display();

    return 0;
}
