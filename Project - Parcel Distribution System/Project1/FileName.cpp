#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

//login
char choice;
string userName;
string userPassword;




/*
Orders -- Module
Implemented and managed through graphs
*/

struct Order {
	//credentials
	string userName;
	string userPassword;
	string address;

	//from inverntory
	string itemName;
	int quantity;
	float price;

	//edge
	int src;
	int dest;
	int wt;

	Order(string userName, string userPassword, string address, string itemName, int quantity, float price, int src, int dest, int wt) {
		this->userName = userName;
		this->userPassword = userPassword;
		this->address = address;
		this->itemName = itemName;
		this->quantity = quantity;
		this->price = price;
		this->src = src;
		this->dest = dest;
		this->wt = wt;
	}
};

vector<Order> graph[29];

void createOrder(vector<Order>graph[],Order order) {
	graph[order.src].push_back(Order(order.userName, order.userPassword, order.address, order.itemName, order.quantity, order.price, order.src, order.dest, order.wt));
}


void printGraph(vector<Order>graph[], Order order) {
	queue<Order> queue;
	bool visited[29][29]; // 2D array to mark visited orders
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 29; j++)
			visited[i][j] = false;

	queue.push(order);
	while (!queue.empty()) {
		Order currentOrder = queue.front();
		queue.pop();

		if (!visited[currentOrder.src][currentOrder.dest]) {
			cout << "Customer name : " << currentOrder.userName << endl
				<< "Customer password : " << currentOrder.userPassword << endl
				<< "Customer Address : " << currentOrder.address << endl
				<< "Item name : " << currentOrder.itemName << endl
				<< "Item Quantity : " << currentOrder.quantity << endl
				<< "Item Price : " << currentOrder.price << endl
				<< "Source vertex : " << currentOrder.src << endl
				<< "Destination vertex : " << currentOrder.dest << endl
				<< "Distnce from src-dest : " << currentOrder.wt << endl;
			cout << "-----------------------------------" << endl;

			visited[currentOrder.src][currentOrder.dest] = true;

			for (int i = 0; i < graph[currentOrder.src].size(); i++) {
				queue.push(graph[currentOrder.src][i]);
			}
			for (int i = 0; i < graph[currentOrder.dest].size(); i++) {
				queue.push(graph[currentOrder.dest][i]);
			}
		}
	}
}
void searchOrder(vector<Order>graph[], Order order,string userName,string userPassword) {
	queue<Order> queue;
	bool visited[29][29]; // 2D array to mark visited orders
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 29; j++)
			visited[i][j] = false;

	queue.push(order);
	while (!queue.empty()) {
		Order currentOrder = queue.front();
		queue.pop();

		if (!visited[currentOrder.src][currentOrder.dest]) {
			if (currentOrder.userName == userName and currentOrder.userPassword == userPassword) {
				cout << "Customer name : " << currentOrder.userName << endl
					<< "Customer password : " << currentOrder.userPassword << endl
					<< "Customer Address : " << currentOrder.address << endl
					<< "Item name : " << currentOrder.itemName << endl
					<< "Item Quantity : " << currentOrder.quantity << endl
					<< "Item Price : " << currentOrder.price << endl
					<< "Source vertex : " << currentOrder.src << endl
					<< "Destination vertex : " << currentOrder.dest << endl
					<< "Distnce from src-dest : " << currentOrder.wt << endl;
				cout << "-----------------------------------" << endl;
			}
			visited[currentOrder.src][currentOrder.dest] = true;

			for (int i = 0; i < graph[currentOrder.src].size(); i++) {
				queue.push(graph[currentOrder.src][i]);
			}
			for (int i = 0; i < graph[currentOrder.dest].size(); i++) {
				queue.push(graph[currentOrder.dest][i]);
			}
		}
	}
}
struct Pair {
	int node;
	int dist;

	Pair(int node, int dist) {
		this->node = node;
		this->dist = dist;
	}
	bool operator<(const Pair& other) const {
		return this->dist > other.dist;
	}
};
void dijkstra(vector<Order> graph[], Order order) {
	priority_queue<Pair> pq;

	int distance[29];
	for (int i = 0; i < 29; i++) {
		if (i != order.src)
			distance[i] = numeric_limits<int>::max();
	}
	distance[order.src] = 0;

	bool visited[29];
	for (int i = 0; i < 29; i++)
		visited[i] = false;

	pq.push(Pair(order.src, 0));

	while (pq.empty() == false) {
		Pair current = pq.top();
		pq.pop();

		if (visited[current.node] == false) {
			visited[current.node] = true;
			for (int i = 0; i < graph[current.node].size(); i++) {
				Order o = graph[current.node][i];
				int u = o.src;
				int v = o.dest;
				if (distance[u] + o.wt < distance[v]) {
					distance[v] = distance[u] + o.wt;
					pq.push(Pair(v, distance[v]));
				}
			}
		}
	}
	cout << "Shortest paths from warehouse to all delivery points\n";


	for (int i = 0; i < 29; i++) {
		if (distance[i] == numeric_limits<int>::max()) {
			continue;
		}
		else {
		cout << "Vertex " << i << " : " << distance[i] << "km\n";
		}
	}



}


/*
Login -- Module
Implemented and managed through HashTable
*/

struct hashTable {
	string userName; //key
	string userPassword;
};
const int hashTableSize = 29;
hashTable table[hashTableSize];

void initHashTable() {
	for (int i = 0; i < hashTableSize; i++)
		table[i].userName = "";
}

int hashFunction(string userName) {
	int key = 0;
	for (int i = 0; i < userName.length(); i++)
		key += userName[i];
	return key % hashTableSize;
}

void insertRecord(string userName, string userPassword) {
	int indexOfKey = hashFunction(userName);

	if (table[indexOfKey].userName == "") {
		table[indexOfKey].userName = userName;
		table[indexOfKey].userPassword = userPassword;
	}
	else {
		for (int i = 0; i < hashTableSize; i++) {
			if (table[indexOfKey].userName != "") {
				indexOfKey = (indexOfKey + 1) % hashTableSize;
			}
			
		}
		table[indexOfKey].userName = userName;
		table[indexOfKey].userPassword = userPassword;
		
	}
}

void searchRecord(string userName, string userPassword) {
	int indexOfKey = hashFunction(userName);

	if (table[indexOfKey].userName == userName and table[indexOfKey].userPassword == userPassword) {
		cout << table[indexOfKey].userName <<"-";
		cout << table[indexOfKey].userPassword;
		cout << "-> Search was successfull...\n";
	}
	
}
void printHashTable() {
	for (int i = 0; i < hashTableSize; i++) {
		cout << i << " ----- " << table[i].userName << "   " << table[i].userPassword << "\n";
	}
}



/*
Inventory -- Module
Implemented and managed through BST
*/

struct item {
	string itemName;
	int availableQuantity;
	float perUnitPrice;
	item* left;
	item* right;
};

item* createNode(string itemName, int availableQuantity, float perUnitPrice) {
	item* root = new item();
	root->itemName = itemName;
	root->availableQuantity = availableQuantity;
	root->perUnitPrice = perUnitPrice;
	root->right = NULL;
	root->left = NULL;
	return root;
}

item* insertItem(item* root, string itemName, int availableQuantity, float perUnitPrice) {
	if (root == NULL) {
		return createNode(itemName, availableQuantity, perUnitPrice);
	}
	if (root->perUnitPrice > perUnitPrice) {
		root->left = insertItem(root->left, itemName, availableQuantity, perUnitPrice);
	}
	else {
		root->right = insertItem(root->right, itemName, availableQuantity, perUnitPrice);
	}
	return root;
}

item* findMin(item* root) {
	item* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

item* findMax(item* root) {
	item* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

item* searchItem(item* root, string itemName, int key) {
	// Base case: root is null or key is present at root
	if (root == NULL || root->perUnitPrice == key and root->itemName == itemName) {
		return root;
	}

	// Key is greater than root's key
	if (key > root->perUnitPrice) {
		return searchItem(root->right, itemName,key);
	}
	// Key is smaller than root's key
	else {
		return searchItem(root->left, itemName, key);
	}
}

item* removeItem(item* root, float price) {
	if (root == NULL) {
		return root;
	}
	if (root->perUnitPrice > price) {
		root->left = removeItem(root->left, price);
	}
	else if (root->perUnitPrice< price) {
		root->right = removeItem(root->right, price);
	}
	else {
		if (root->left == NULL) {
			item* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			item* temp = root->left;
			delete root;
			return temp;
		}
		item* temp = findMin(root->right);
		root->itemName = temp->itemName;
		root->availableQuantity = temp->availableQuantity;
		root->perUnitPrice = temp->perUnitPrice;
		root->right = removeItem(root->left, temp->perUnitPrice);
	}
	return root;
}

void preorderTraversal(item* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << "Item Name: " << root->itemName << endl;
		cout << "Available Quantity: " << root->availableQuantity << endl;
		cout << "Per Unit Price: " << root->perUnitPrice << endl;
		cout << "-----------------------------------" << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(item* root) {
	if (root == NULL) {
		return;
	}
	else {
		inorderTraversal(root->left);
		cout << "Item Name: " << root->itemName << endl;
		cout << "Available Quantity: " << root->availableQuantity << endl;
		cout << "Per Unit Price: " << root->perUnitPrice << endl;
		cout << "-----------------------------------" << endl;
		inorderTraversal(root->right);
	}
}

void postorderTraversal(item* root) {
	if (root == NULL) {
		return;
	}
	else {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout << "Item Name: " << root->itemName << endl;
		cout << "Available Quantity: " << root->availableQuantity << endl;
		cout << "Per Unit Price: " << root->perUnitPrice << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;
	}
}



//doesn't belong to inventory module
void placeOrder(item* itemToBuy) {
	int itemQuantity;
	float totalPrice;
	string customerAddress;
	int src, dest, wt;

	cout << "Enter Quantity : ";
	cin >> itemQuantity;

	if (itemQuantity > itemToBuy->availableQuantity)
		cout << "-> That many items aren't available :(" << endl;
	else {
		totalPrice = itemToBuy->perUnitPrice * itemQuantity;

		cout << "Enter your residential address : ";
		cin >> customerAddress;
		cout << "Enter source vertex : ";
		cin >> src;
		cout << "Enter destination vertex : ";
		cin >> dest;
		cout << "Enter distance from src to dest : ";
		cin >> wt;

		//all the details are passed as a vertex to graph
		Order order = Order(userName, userPassword, customerAddress, itemToBuy->itemName, itemQuantity, totalPrice, src, dest, wt);
		createOrder(graph, order);
		//printGraph(graph,order);
		cout << "-> Your order was successfully placed, A receipet has been generated..." << endl;
		

	}
	//generate receipt here
}

int main() {

	//Predefined Items
	item* root = createNode("Travel Backpack", 2500, 5700);
	insertItem(root, "Eye Mask", 4000, 2100);
	insertItem(root, "First Aid Kit", 1700, 1100);
	insertItem(root, "Water Bottle", 3000, 270);
	insertItem(root, "Sleeping Bag", 2113, 3400);
	insertItem(root, "Hiking Poles", 3210, 1790);


	//predefined customers
	insertRecord("Raza", "1234");
	insertRecord("Junaid", "981");
	insertRecord("Ahmad", "873");
	insertRecord("Ali", "128");
	insertRecord("Nimra", "34939");
	insertRecord("Alina", "349838");
	insertRecord("Alishba", "434");
	insertRecord("Sana", "sd8");
	insertRecord("Sadia", "3498d");
	insertRecord("Saim", "39i43");



	//predefined orders
	Order order1 = Order( "Raza", "1234", "abc street", "Water Bottle", 10, 2700, 0, 1, 12);
	Order order2 = Order("Junaid ", "981", "block12", "Eye Mask", 12, 25200, 0, 5, 12);
	Order order3 = Order("Ahmad", "873", "xyz street", "Sleeping Bag", 34, 115600, 0, 2, 12);
	Order order4 = Order("Ali", "128", "phase4", "Hiking Poles", 7, 12530, 0, 3, 12);
	Order order5 = Order("Nimra", "34939", "sadar", "Water Bottle", 12, 3240, 1, 4, 12);
	Order order6 = Order("Alina", "349838", "malir", "Travel Backpack", 4, 22800, 1, 5, 12);
	Order order7 = Order("Alishba", "434", "gulshan", "Sleeping Bag", 10, 34000, 1, 3, 12);
	Order order8 = Order("Sana", "sd8", "jauhar", "Eye Mask", 8, 16800, 2, 9, 12);
	Order order9 = Order("Sadia", "3498d", "new nazimabad", "First Aid Kit", 1, 1100, 2, 8, 12);
	Order order10 = Order("Saim", "39i43", "new karachi", "Water Bottle", 1, 270, 2, 7, 12);

	createOrder(graph, order1);
	createOrder(graph, order2);
	createOrder(graph, order3);
	createOrder(graph, order4);
	createOrder(graph, order5);
	createOrder(graph, order6);
	createOrder(graph, order7);
	createOrder(graph, order8);
	createOrder(graph, order9);
	createOrder(graph, order10);
	printGraph(graph, order1);


loginMenu:

	cout << "============================================\n"
		<< "        Parcel Distribution System\n"
		<< "============================================\n";

	cout << "1. Login as Admin" << endl
		<< "2. Login as Customer" << endl;
	cin >> choice;
	

	//will be used in all menus
	string itemName;
	int itemQuantity;
	float price;

	if (choice == '1') {
		//admin
		cout << "============================================\n"
			<< "              Login as Admin\n"
			<< "============================================\n";


		cout << "Enter username : ";
		cin >> userName;
		cout << "Enter password : ";
		cin >> userPassword;

		if (userName == "admin123" and userPassword == "admin123") {
			
			cout << "-> Login successfull...\n" << endl;
			//admin menu goes here
		adminMenu:
			cout << "---------------Inventory---------------" << endl;

			cout << "1. Add An Item" << endl
				<< "2. Search An Item" << endl
				<< "3. Remove An Item" << endl
				<< "4. Display Inventory" << endl
				<< "5. Show product with smallest price" << endl
				<< "6. Show product with largest price\n" << endl;

			cout << "----------------Customers---------------" << endl;
			cout << "7. Print customer details" << endl
			 	 << "8. Search customer\n" << endl;

			cout << "-----------------Routes-----------------" << endl;
			cout << "9. Display orders" << endl
				<< "0. Deliver orders\n" << endl;
			cin >> choice;

			

			if (choice == '1') {
				//add item in inventory

				cout << "Enter Product Name: " << endl;
				cin >> itemName;
				cout << "Enter Product Quantity: " << endl;
				cin >> itemQuantity;
				cout << "Enter Price: " << endl;
				cin >> price;
				insertItem(root, itemName, itemQuantity, price);
				cout << "Item was Added Successfully..." << endl;
				cout << "============================================\n"
					<< "             Available Items\n"
					<< "============================================\n";
				inorderTraversal(root);
				cout << "1. Admin menu"<<endl
					 << "2. Main menu"<<endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '2') {
				//search item from inventory
				cout << "============================================\n"
					<<  "               Search Item\n"
					<<  "============================================\n";
				
				cout << "Enter Item name : ";
				cin.ignore();
				getline(cin, itemName);
				cout << "Enter Price : ";
				cin >> price;
				item* item = searchItem(root, itemName, price);
				cout << "============================================\n"
					<<  "               Product Found\n"
					<<  "============================================\n";
				cout << "Item Name: " << item->itemName << endl;
				cout << "Available Quantity: " << item->availableQuantity << endl;
				cout << "Per Unit Price: " << item->perUnitPrice << endl;
				cout << "---------------------------------------------" << endl;
				cout << endl;
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '3') {
				//delete item from inventory

				cout << "============================================\n"
					<< "               Delete Item\n"
					<< "============================================\n";
				cout << "Enter Name of The Item : ";
				cin.ignore();
				getline(cin, itemName);
				cout << "Enter Price of the product : ";
				cin >> price;
				removeItem(root, price);
				cout << "-> Item was Removed Successfully..." << endl;
				inorderTraversal(root);
				cout << "---------------------------------------------" << endl;
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '4') {
				//print inventory
				cout << "============================================\n"
					<< "             Available Items\n"
					<< "============================================\n";
				inorderTraversal(root);
				cout << "---------------------------------------------" << endl;
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '5') {
				cout << "============================================\n"
					<< "            Smallest size product\n"
					<< "============================================\n";
				item* smallest = findMin(root);
				cout << "Item Name: " << smallest->itemName << endl;
				cout << "Available Quantity: " << smallest->availableQuantity << endl;
				cout << "Per Unit Price: " << smallest->perUnitPrice << endl;
				cout << "-----------------------------------" << endl;
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '6') {
				cout << "============================================\n"
					<< "            Largest size product\n"
					<< "============================================\n";
				item* largest = findMax(root);
				cout << "Item Name: " << largest->itemName << endl;
				cout << "Available Quantity: " << largest->availableQuantity << endl;
				cout << "Per Unit Price: " << largest->perUnitPrice << endl;
				cout << "-----------------------------------" << endl;
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '7') {
				cout << "============================================\n"
					<<  "             Customer Details\n"
					<<  "============================================\n";
				printHashTable();
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '8') {
				cout << "============================================\n"
					<<  "            Search Customer\n"
					<<  "============================================\n";
				cout << "Enter user name :";
				cin >> userName;
				cout << "Enter password : ";
				cin >> userPassword;
				searchRecord(userName,userPassword);
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '9') {
				//print orders
				cout << "============================================\n"
					<<  "             Placed Orders\n"
					<<  "============================================\n";
				printGraph(graph, order1);
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else if (choice == '0') {
				cout << "============================================\n"
					<<  "               Route Design\n"
					<<  "============================================\n";
				dijkstra(graph, order1);
				cout << "1. Admin menu" << endl
					<< "2. Main menu" << endl;
				cin >> choice;
				if (choice == '1') {
					goto adminMenu;
				}
				else if (choice == '2') {
					goto loginMenu;
				}
				else {
					cout << "Invalid option...\n";
				}
			}
			else {
				cout << "Invalid Option..." << endl;
			}
		}
		else if (userName == "admin123" and userPassword != "admin123") {
			cout << "Incorrect password...";
		}
		else if (userName != "admin123" and userPassword == "admin123") {
			cout << "Incorrect user name...";
		}
		else {
			cout << "Wrong credentials...";
		}
	}
	else if (choice == '2') {
		//customer login
		cout << "============================================\n"
			<< "              Login as Customer\n"
			<< "============================================\n";
	customerMenu:
		cout << "1. Track your parcel\n"
			<< "2. Create account\n"
			<< "3. Display inventory\n";
		cin >> choice;

		if (choice == '1') {
			//login to existing acc will fetch the details of placed orders
			cout << "============================================\n"
				<< "                Track Parcel \n"
				<< "============================================\n";

			cout << "Enter username : ";
			cin.ignore();
			getline(cin, userName);
			cout << "Enter password : ";
			getline(cin, userPassword);

			searchRecord(userName, userPassword);
			searchOrder(graph, order1, userName, userPassword);
			cout << "-----------------------------------" << endl;

			cout << "1. Customer menu" << endl
				<< "2. Main menu" << endl;
			cin >> choice;
			if (choice == '1') {
				goto customerMenu;
			}
			else if (choice == '2') {
				goto loginMenu;
			}
			else {
				cout << "Invalid option....\n";
			}
		}

		else if (choice == '2') {
			//create an acc to place order
			cout << "============================================\n"
				<< "           Create a new account \n"
				<< "============================================\n";

			cout << "Enter username : ";
			cin.ignore();
			getline(cin, userName);
			cout << "Enter password : ";
			getline(cin, userPassword);
			insertRecord(userName, userPassword);
			cout << "-> Your Account was created successfully...\n";


			int counter = -1;
		buyItem:
			cout << "============================================\n"
				<< "             Available Items\n"
				<< "============================================\n";
			inorderTraversal(root);


			cout << "Enter name of the item to buy : ";
			if (counter != -1) {
				cin.ignore();
			}
			getline(cin, itemName);
			cout << "Enter price : ";
			cin >> price;

			item* item = searchItem(root, itemName, price);
			placeOrder(item);
			printGraph(graph, order1);

			counter++;
			cout << "Do you Want to place another order (Y/N) : ";
			cin >> choice;
			if (choice == 'y' or choice == 'Y') {
				goto buyItem;
			}
			else if (choice == 'n' or choice == 'N') {
				goto loginMenu;
			}
			else {
				cout << "Invalid option...\n";
			}

		}
		else if (choice == '3') {
			cout << "============================================\n"
				<< "             Available Items\n"
				<< "============================================\n";
			inorderTraversal(root);
			cout << "1. Customer menu" << endl
				<< "2. Main menu" << endl;
			cin >> choice;
			if (choice == '1') {
				goto customerMenu;
			}
			else if (choice == '2') {
				goto loginMenu;
			}
			else {
				cout << "Invalid option....\n";
			}
		}
		else if (choice == '0') {
			goto loginMenu;
		}

	}
	return 0;
}