#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

void countSameValuesInArray() {
	map<double, int> numbers;
	vector<double> order;
	string line;
	getline(cin, line);
	istringstream mainLine(line);

	while (mainLine >> line) {
		numbers[stod(line)]++;
		auto it = find(order.begin(),order.end(), stoi(line));
		if(it != order.end()) {
			continue; 
		}
		else {
			order.push_back(stod(line));
		}
		

	}
	//-2.5 - 3 times
	for (const auto& word : order) {
		auto it = numbers.find(word);
		if (it != numbers.end() && it->second > 0) {
			cout << it->first << " - " << it->second << " times" << endl;
		}
	}
	
}

void averageStudentGrades() {
	int n;
	map<string, vector<double>> students;
	cin >> n;

	for(size_t i = 0; i < n; i++) {
		string name;
		double grade;
		cin >> name >> grade;
		
		students[name].push_back(grade);
	}

	for (const auto& student : students) {
		cout << student.first << " -> ";
		double average = 0.0;
		for (const auto& grade : student.second) {
			cout << fixed << setprecision(2) << grade << " ";
			average += grade;
		}
		average /= student.second.size();
		cout << "(avg: " << fixed << setprecision(2) << average << ")" << endl;
	}
}

void continents() {
	map<string, map<string, vector<string>>> continents_Countries_Cities;
	size_t n;
	cin >> n;

	for (auto i = 0; i < n; i++) {
		string continent, country, city;
		cin >> continent >> country >> city;
		continents_Countries_Cities[continent][country].push_back(city);
	}

	for (auto it = continents_Countries_Cities.begin(); it != continents_Countries_Cities.end(); it++) {
		cout << it->first << ":" << endl;
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			cout << "  " << it2->first << " -> ";
			vector<string> sortedCities = it2->second;
			sort(sortedCities.begin(), sortedCities.end());
			for (size_t i = 0; i < sortedCities.size(); i++) {
				if (i > 0) {
					cout << ", ";
				}
				cout << sortedCities[i];
			}
			cout << endl;
		}
	}
}

void recordUniqueNames() {
	set<string> names;
	vector<string> order;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string name;
		cin >> name;
		names.insert(name);

		auto it = find(order.begin(), order.end(), name);
		if (it == order.end()) {
			order.push_back(name);
		}
		else {
			continue;
		}
	}

	for (const auto& word : order) {
		auto it = names.find(word);
		if (it != names.end()) {
			cout << *it<< endl;
		}
	}
	
}

void parkingLot() {
	string command;
	map<string, string> parkingLot;

	while (cin >> command && command != "END") {
		string carNumber;
		cin >> carNumber;
		
		parkingLot[carNumber] = command;
		
	}

	int carsIn = 0;
	for (const auto& entry : parkingLot) {
		if (entry.second == "IN,") {
			cout << entry.first << endl;
			carsIn++;
		}
	}

	if(carsIn == 0){
		cout << "Parking Lot is Empty" << endl;
		return;
	}

}

void recordUniqueUsernames() {
	set<string> names;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		names.insert(name);
	}

	

	for (const auto& word : names) {
		cout << word << endl;
	}
}

void setsOfElems() {
	int size1, size2;
	set<int> set1, set2, setNumbers;
	cin >> size1 >> size2;

	for(int i = 0; i < size1; i++) {
		int number;
		cin >> number;
		set1.insert(number);
	}

	for(int i = 0; i < size2; i++) {
		int number;
		cin >> number;
		set2.insert(number);
	}

	for (const auto& elem : set1) {
		if (set2.find(elem) != set2.end()) {
			setNumbers.insert(elem);
		}
	}

	for (const auto& elem : setNumbers) {
		cout << elem << " ";
	}
}

void evenTimes() {
	map<int,int> numbers;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		numbers[number]++;
		
	}
	for (const auto& elem : numbers) {
		if(elem.second % 2 == 0) {
			cout << elem.first << endl;
			return;
		}
	}
}

int main()
{
	setsOfElems();
}

