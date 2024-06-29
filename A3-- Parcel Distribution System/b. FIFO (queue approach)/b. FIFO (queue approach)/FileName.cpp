#include <iostream>
#include <queue>
using namespace std;

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
float totalDistance = 0;

void printOrderList(queue<Order> orderList) {

	int counter = 1;
	while(orderList.empty() == false){
		Order currentOrder = orderList.front();
		orderList.pop();
		cout << "---- Order " << counter << " ----\n";
		cout << "Order number : " << currentOrder.orderNumber << "\n"
			<< "Customer Name :" << currentOrder.customerName << "\n"
			<< "Mode of Transport" << currentOrder.modeOfTransport << "\n"
			<< "Distance : " << currentOrder.distance << "\n"
			<< "Deadline : " << currentOrder.deadline << "\n";
		totalDistance += currentOrder.distance;
		counter++;
		cout << "\n";
	}
}
void expenseCalculation(queue<Order> orderList) {
	
	float petrolUsed = totalDistance / 35;
	float costOfPetrol = petrolUsed * 289.33;
	cout << "Total distance covered (in kilometeres) : " << totalDistance << "\n"
		<< "Amount of petrol used (in liters) : " << petrolUsed << "\n"
		<< "Cost of petrol per liter : 289.33 rupees\n"
		<< "Cost of petrol for " << totalDistance << "kms : " << costOfPetrol << "rupees\n";

}
int main() {
	queue<Order> orderList;

	Order order1 = Order("Raza", 20, "Road", 12, "4/June/22");
	Order order2 = Order("Ali", 17, "Truck", 34, "1/June/22");
	Order order3 = Order("Shayan", 34, "Rail", 389, "7/June/22");
	Order order4 = Order("Rehman", 29, "Bus", 31, "4/June/22");
	Order order5 = Order("Aimen", 83, "Rail", 19, "28/June/22");
	Order order6 = Order("Muskan", 16, "Rail", 39, "10/June/22");
	Order order7 = Order("Zubair", 58, "Truck", 112, "8/June/22");
	Order order8 = Order("Alishba", 42, "Air", 921, "6/June/22");
	Order order9 = Order("Saireen", 39, "Road", 31, "9/June/22");
	Order order10 = Order("Ammar", 65, "Bus", 39, "23/June/22");
	Order order11 = Order("Ahmad", 76, "Truck", 91, "27/June/22");
	Order order12 = Order("Zikria", 51, "Road", 23, "30/June/22");
	Order order13 = Order("Manahil", 93, "Bus", 71, "5/June/22");
	Order order14 = Order("Mishkat", 27, "Rail", 480, "4/June/22");
	Order order15 = Order("Saad", 43, "Air", 347, "18/June/22");

	orderList.push(order1);
	orderList.push(order2);
	orderList.push(order3);
	orderList.push(order4);
	orderList.push(order5);
	orderList.push(order6);
	orderList.push(order7);
	orderList.push(order8);
	orderList.push(order9);
	orderList.push(order10);
	orderList.push(order11);
	orderList.push(order12);
	orderList.push(order13);
	orderList.push(order14);
	orderList.push(order15);


	cout << "============ All Orders ============\n\n";
	cout << "parcels will be delivered in this order...\n";
	printOrderList(orderList);

	cout << "============ Expense required ============\n\n";
	expenseCalculation(orderList);
	return 0;
}