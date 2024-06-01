#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

struct Order {
	string customerName;
	int orderNumber;
	string modeOfTransport;
	int distance;
	string deadline;

	Order(string customerName, int orderNumber, string modeOfTransport, int distance, string deadline) {
		this->customerName = customerName;
		this->orderNumber = orderNumber;
		this->modeOfTransport = modeOfTransport;
		this->distance = distance;
		this->deadline = deadline;
	}
};

void heapify(vector<Order> &heap,int size,int i) {
	int largest = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	if (l < size && heap[l].orderNumber > heap[largest].orderNumber)
		largest = l;
	if (r < size && heap[r].orderNumber > heap[largest].orderNumber)
		largest = r;

	if (largest != i)
	{
		swap(heap[i].customerName, heap[largest].customerName);
		swap(&heap[i].orderNumber, &heap[largest].orderNumber);
		swap(heap[i].modeOfTransport, heap[largest].modeOfTransport);
		swap(heap[i].distance, heap[largest].distance);
		swap(heap[i].deadline, heap[largest].deadline);

		heapify(heap, size, largest);
	}

}

void insert(vector<Order>& heap, Order order)
{

	heap.push_back(order);
	int size = heap.size();
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(heap, size, i);
	}
}

void heapSort(vector<Order>& heap) {
	int size = heap.size();

	for (int i = size / 2 - 1; i >= 0; i--)  //heapifying heap if necessary
		heapify(heap, size, i);

	for (int i = size - 1; i >= 0; i--) {    //sorting heap
		swap(heap[0].customerName, heap[i].customerName);
		swap(&heap[0].orderNumber, &heap[i].orderNumber);
		swap(heap[0].modeOfTransport, heap[i].modeOfTransport);
		swap(heap[0].distance, heap[i].distance);
		swap(heap[0].deadline, heap[i].deadline);
		heapify(heap, i, 0);
	}

	int counter = 1;
	for (int i = size - 1; i >= 0; i--) {    //defining priorites
		cout << "---- Priority"<<counter<<" ----\n";

		cout << "Order number : " << heap[i].orderNumber << "\n"
			<< "Customer Name :" << heap[i].customerName << "\n"
			<< "Mode of Transport" << heap[i].modeOfTransport << "\n"
			<< "Distance : " << heap[i].distance << "\n"
			<< "Deadline : " << heap[i].deadline << "\n";

		cout << "\n";
		counter += 1;
	}
}


void printList(vector<Order>& heap)
{
	for (int i = 0; i < heap.size(); ++i) {
		cout << "---- Order "<<i+1<<" ----\n";

		cout <<"Order number : "<< heap[i].orderNumber << "\n"
			<< "Customer Name :"<<heap[i].customerName << "\n"
			<< "Mode of Transport"<<heap[i].modeOfTransport << "\n"
			<< "Distance : "<<heap[i].distance << "\n"
			<< "Deadline : "<<heap[i].deadline << "\n";
	
		cout << "\n";
	}
}

int main() {

	vector<Order> heap;
	
	Order order1 = Order("Raza",20,"Road",12,"4/June/22");
	Order order2 = Order("Ali", 17, "Truck", 34, "4/June/22");
	Order order3 = Order("Shayan", 34, "Rail", 389, "4/June/22");
	Order order4 = Order("Rehman", 29, "Bus", 31, "4/June/22");
	Order order5 = Order("Aimen", 83, "Rail", 19, "4/June/22");
	Order order6 = Order("Muskan", 16, "Rail", 39, "4/June/22");
	Order order7 = Order("Zubair", 58, "Truck", 112, "4/June/22");
	Order order8 = Order("Alishba", 42, "Air", 921, "4/June/22");
	Order order9 = Order("Saireen", 39, "Road", 31, "4/June/22");
	Order order10 = Order("Ammar", 65, "Bus", 39, "4/June/22");
	Order order11 = Order("Ahmad", 76, "Truck", 91, "4/June/22");
	Order order12 = Order("Zikria", 51, "Road", 23, "4/June/22");
	Order order13 = Order("Manahil", 93, "Bus", 71, "4/June/22");
	Order order14 = Order("Mishkat", 27, "Rail", 480, "4/June/22");
	Order order15 = Order("Saad", 43, "Air", 347, "4/June/22");


	insert(heap, order1);
	insert(heap, order2);
	insert(heap, order3);
	insert(heap, order4);
	insert(heap, order5);
	insert(heap, order6);
	insert(heap, order7);
	insert(heap, order8);
	insert(heap, order9);
	insert(heap, order10);
	insert(heap, order11);
	insert(heap, order12);
	insert(heap, order13);
	insert(heap, order14);
	insert(heap, order15);


	cout << "============ All Orders ============\n\n";
	printList(heap);

	cout << "============ Orders In Priority ============\n\n";
	heapSort(heap);

	return 0;
}