#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void officeAdministrator() {
	map<string, set<int>> emploiesNRooms;
	vector<string> neededNames;

	string input;
	int room;
	while (cin >> input && input != "END") {
		cin >> room;
		emploiesNRooms[input].insert(room);
	}

	while (cin >> input && input != "END")
	{
		neededNames.push_back(input);
	}

	auto itMap = emploiesNRooms.begin();
	for (int i = 0; i < neededNames.size(); i++) {
		auto itFound = emploiesNRooms.find(neededNames[i]);


		if (itFound != emploiesNRooms.end()) {
			itMap = itFound;
			cout << neededNames[i] << ": ";
			for (const int &elem:itMap->second) {
				cout << elem << ' ';
			}
			cout << endl;
			
		}
		else {
			cout << neededNames[i] << ": Not found!" << endl;
		}
	}

}

bool isDiagnal(int row,int col, int rows,int cols,int dims) {
	bool isDiagonal = row == col || row == 0 && col == cols - 1 
					|| row == rows - 1 && col == 0 || row + col == dims - 1;
	
	if (isDiagonal) {
		return false;
	}
	else {
		return true;
	}
}
void matrixSum() {
	int dims;
	cin >> dims;
	int rows = dims, cols = dims;

	int m[20][20] = { 0 };

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> m[row][col];
		}
	}

	int sum = 0;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (isDiagnal(row, col, rows, cols, dims)) {
				if (m[row][col] % 2 == 1) {
					sum += m[row][col];
				}
			}
		}
	}

	cout << "The sum is: " << sum << endl;


}

void inventor() {
	int numberOfCities;
	cin >> numberOfCities;

	map<string, double>cities;

	for (int i = 0; i < numberOfCities;i++) {
		string name;
		double price, quantity;
		cin >> name >> price >> quantity;

		toupper(name[0]);

		auto it = cities.find(name);
		if (it != cities.end()) {
			i--;
		}

		cities[name] += price * quantity;
	}

	for (auto it = cities.begin(); it != cities.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}


}

int main()
{
	inventor();
}
