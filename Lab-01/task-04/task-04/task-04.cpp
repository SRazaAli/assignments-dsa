#include <iostream>
using namespace std;

int main() {

	int marks[7];
	int avg = 0;
	int maxMarks = 0;
	int sum =0;
	for (int i = 0; i < 7; i++) {		//taking input
		cout << "Enter the marks of student no : " << i + 1<<endl;
		cin >> marks[i];
	}
	for (int i = 0; i < 7; i++) {		//calc avg
		sum += marks[i];
	}
	avg = sum / 7;
	cout << "Students having marks above average are : \n";
	for(int i = 0;i<7;i++){			//printing result
		marks[i] > avg ? cout << marks[i] << "\t" :cout << " ";
	}
	for (int i = 0; i < 7; i++) {
		if (marks[i] > maxMarks)
			maxMarks = marks[i];
	}
	cout << "Highest marks : " << maxMarks << endl;

	for (int i = 0; i < 7; i++) {
		if (marks[i] < maxMarks)
			maxMarks = marks[i];
	}
	cout << "Lowest marks : " << maxMarks << endl;

	return 0;
}