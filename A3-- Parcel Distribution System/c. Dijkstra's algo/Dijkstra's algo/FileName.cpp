#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Edge {
	int src;
	int dest;
	int wt;

	Edge(int src, int dest, int wt) {
		this->src = src;
		this->dest = dest;
		this->wt = wt;
	}
};

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
int totalDistance = 0;
void createGraph(vector<Edge> graph[]) {
	graph[0].push_back(Edge(0, 1, 10));
	graph[0].push_back(Edge(0, 9, 7));
	graph[0].push_back(Edge(0, 4, 2));
	graph[0].push_back(Edge(0, 15, 1));

	graph[1].push_back(Edge(1, 2, 7));
	graph[1].push_back(Edge(1, 5, 8));

	graph[2].push_back(Edge(2, 3, 3));
	graph[2].push_back(Edge(2, 7, 3));

	graph[3].push_back(Edge(3, 4, 7));
	graph[3].push_back(Edge(3, 9, 6));
	graph[3].push_back(Edge(3, 11, 9));

	graph[4].push_back(Edge(4, 5, 3));
	graph[4].push_back(Edge(4, 12, 6));
	graph[4].push_back(Edge(4, 14, 5));

	graph[5].push_back(Edge(5, 6, 4));
	graph[5].push_back(Edge(5,10, 1));
	graph[5].push_back(Edge(5, 13, 2));

	graph[6].push_back(Edge(6, 7, 7));
	graph[6].push_back(Edge(6, 11, 1));
	graph[6].push_back(Edge(6, 1, 7));

	graph[7].push_back(Edge(7, 8, 8));
	graph[7].push_back(Edge(7, 13, 8));

	graph[8].push_back(Edge(8, 9, 4));
	graph[8].push_back(Edge(8, 0, 7));
	graph[8].push_back(Edge(8, 2, 1));

	graph[9].push_back(Edge(9, 10, 4));
	graph[9].push_back(Edge(9, 14, 2));

	graph[10].push_back(Edge(10, 11, 9));
	graph[10].push_back(Edge(10, 1, 1));
	graph[10].push_back(Edge(10, 2, 5));
	graph[10].push_back(Edge(10, 5, 7));

	graph[11].push_back(Edge(11, 12, 7));
	graph[11].push_back(Edge(11, 0, 7));

	graph[12].push_back(Edge(12, 13, 5));
	graph[12].push_back(Edge(12, 4, 4));
	graph[12].push_back(Edge(12, 7, 7));

	graph[13].push_back(Edge(13, 14, 8));
	graph[13].push_back(Edge(13, 8, 1));
	graph[13].push_back(Edge(13, 3, 1));

	graph[14].push_back(Edge(14, 15, 9));
	graph[14].push_back(Edge(14, 6, 4));
	graph[14].push_back(Edge(14, 9, 1));

	graph[15].push_back(Edge(15, 6, 10));
	graph[15].push_back(Edge(15, 1, 9));


}


void dijkstra(vector<Edge> graph[],int src) {
	priority_queue<Pair> pq;
	
	int distance[16];
	for (int i = 0; i < 16; i++) {
		if (i != src)
			distance[i] = numeric_limits<int>::max();
	}
	distance[src] = 0;

	bool visited[16];
	for (int i = 0; i < 16; i++)
		visited[i] = false;

	pq.push(Pair(src, 0));

	while (pq.empty() == false) {
		Pair current = pq.top();
		pq.pop();

		if (visited[current.node] == false) {
			visited[current.node] = true;
			for (int i = 0; i < graph[current.node].size(); i++) {
				Edge e = graph[current.node][i];
				int u = e.src;
				int v = e.dest;
				if (distance[u] + e.wt < distance[v]) {
					distance[v] = distance[u] + e.wt;
					pq.push(Pair(v, distance[v]));
				}
			}
		}
	}
	cout << "============================================================\n"
		<< "     Distance From Warehouse To Customer's Destination\n"
		<< "============================================================\n"
		<< "Shortest paths from warehouse to customer's location are given as\n";

	
	for (int i = 0; i < 16; i++) {
		if (i == 0)
			cout << "Warehouse : " << distance[i] << " km\n";
		else
		cout <<"Order "<<i <<" : "<< distance[i] << " km\n";
	}

	
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 15; j++) {
			if (distance[j] > distance[j + 1])
				swap(distance[j], distance[j + 1]);
		}
	}
	cout << "============================================================\n"
		<< "	      Order of Parcel Distribution\n"
		<< "============================================================\n"
		<< "The order in which the parcels will be distribued is given as\n";

	for (int i = 0; i < 16; i++) {
		if (i == 0)
			cout << "Warehouse : " << distance[i] << " km\n";
		else {
			cout << "Order " << i << " : " << distance[i] << " km\n";
			totalDistance += distance[i];
		}
	}
}
void expenseCalculation() {
	cout << "============================================================\n"
		<< "	      Details and Summary of Expenditure\n"
		<< "============================================================\n";

	float petrolUsed = totalDistance / 35;
	float costOfPetrol = petrolUsed * 289.33;
	cout << "Total distance covered (in kilometeres) : " << totalDistance << "\n"
		<< "Amount of petrol used (in liters) : " << petrolUsed << "\n"
		<< "Cost of petrol per liter : 289.33 rupees\n"
		<< "Cost of petrol for " << totalDistance << "kms : " << costOfPetrol << "rupees\n";

}
int main() {

	vector<Edge> graph[16];

	createGraph(graph);
	
	dijkstra(graph, 0);
	
	expenseCalculation();
	
	return 0;
}