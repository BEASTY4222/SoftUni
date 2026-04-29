#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void belowAverage() {
	int n, sum = 0;
	cin >> n;

	vector<int> numbers;
	numbers.reserve(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
		sum += temp;
	}

	int average = sum / n;

	int evenSum = 0, oddSum = 0, index = 0;
	for (int i = 0; i < n; i++, index++) {
		if (numbers[i] <= average) {
			if (index % 2 == 0) {
				evenSum += numbers[i];
			}
			else {
				oddSum += numbers[i];
			}
		}
		else
		{
			continue;
		}
	}

	cout << evenSum * oddSum << endl;
}

bool exeptionChars(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void specialItems() {
	string line;
	getline(cin, line);

	char curr = ' ';
	for (int i = 0; i < line.size();) {
		if (line[i] == curr && !exeptionChars(line[i])) {
			line = line.erase(i, 1);
		}
		else {
			curr = line[i];
			i++;
		}
	}

	cout << line << endl;


}

void machineComands() {
	list<int> numbers;

	while (true)
	{
		string line;
		getline(cin, line);
		if (line == "end")
			break;

		int number;
		istringstream ss(line);

		if(ss >> number)
			numbers.push_back(number);
		else
		{
			if (line == "discard")
				numbers.pop_back();
			else
			{
				int a = numbers.back();
				numbers.pop_back();
				int b = numbers.back();
				numbers.pop_back();

				if (line == "sum")
					numbers.push_back(b + a);
				else if (line == "subtract")
					numbers.push_back(abs(b - a));
				else {
					ostringstream oss;
					oss << b << a;
					string concat = oss.str();

					istringstream iss(concat);
					if (iss >> number) {
						numbers.push_back(number);
					}
				}
			}
		}
	}

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main()
{
	machineComands();
}

