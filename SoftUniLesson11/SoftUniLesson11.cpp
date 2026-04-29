#include <iostream>

using namespace std;

void building() {
	int floors, rooms;
	cin >> floors >> rooms;

	for (int i = floors; i > 0; i--) {

		for (int j = 0; j < rooms; j++) {
			if (i == floors) {
				cout << "L" << i << j << " ";
			}
			else if (i % 2 == 0) {
				cout << "O" << i << j << " ";
			}
			else {
				cout << "A" << i << j << " ";
			}
		}
		cout << endl;
	}
}

void traveling() {
	string destination;
	double neededMoney, money;

	while (cin >> destination && destination != "End") {
		cin >> neededMoney;
		money = 0;

		while (money < neededMoney) {
			double currentMoney;
			cin >> currentMoney;
			money += currentMoney;
		}
		cout << "Going to " << destination << "!" << endl;
	}
}

void twoSum() {
	int start, end, magicNumber;
	cin >> start >> end >> magicNumber;
	int combinationsCount = 0;

	for (int i = start; i <= end; i++) {

		for (int j = start; j <= end; j++) {

			combinationsCount++;
			if (i + j == magicNumber) {
				cout << "Combination N:" << combinationsCount << " (" << i << " + " << j << " = " << magicNumber << ")" << endl;
				return;
			}
		}
	}
	cout << combinationsCount << " combinations - neither equals " << magicNumber << endl;
}

void combinations() {
	int n;
	cin >> n;
	int combinationsCount = 0;
	for (int x1 = 0; x1 <= n; x1++) {
		for (int x2 = 0; x2 <= n; x2++) {
			for (int x3 = 0; x3 <= n; x3++) {
				if (x1 + x2 + x3 == n) {
					combinationsCount++;
				}
			}
		}
	}
	cout << combinationsCount << endl;
}

void multiplicationTable() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}

void clockNestedLoops() {
	for (int h = 0; h < 24; h++) {
		for (int m = 0; m < 60; m++) {
			cout << h << ":" << m << endl;
		}
	}
}


int main()
{
	building();
	return 0;
}
