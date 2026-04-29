#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	string numbers;
	getline(cin, numbers);

	stringstream ss(numbers);
	list<int> numberList;

	int num;
	while (ss >> num)
	{
		numberList.push_back(num);
	}
*/

void manipulations()
{
	string numbers;
	getline(cin, numbers);

	stringstream ss(numbers);
	list<int> numberList;

	int num;
	while (ss >> num)
	{
		numberList.push_back(num);
	}

	string command;
	while (cin >> command && command != "end")
	{
		if (command == "Add")
		{
			int value;
			cin >> value;
			numberList.push_back(value);
		}
		else if (command == "Remove")
		{
			int value;
			cin >> value;
			numberList.remove(value);
		}
		else if (command == "RemoveAt")
		{
			int index;
			cin >> index;
			list<int>::iterator it = numberList.begin();
			advance(it, index);
			numberList.erase(it);
			
		}
		else if (command == "Insert") {
			int index,value;
			cin >> value >> index;
			list<int>::iterator it = numberList.begin();
			advance(it, index);
			numberList.insert(it, value);
		}
	}
	
	for (list<int>::iterator it = numberList.begin(); it != numberList.end(); ++it)
	{
		cout << *it << " ";
	}
	

	
}

void mergingSequences() {
	string numbers1;
	getline(cin, numbers1);
	string numbers2;
	getline(cin, numbers2);

	stringstream ss1(numbers1);
	stringstream ss2(numbers2);
	list<int> numberList1;
	list<int> numberList2;

	int num;
	while (ss1 >> num)
	{
		numberList1.push_back(num);
	}
	while (ss2 >> num)
	{
		numberList2.push_back(num);
	}

	list<int> mergedList;

	while (!numberList1.empty() || !numberList2.empty())
	{
		if (!numberList1.empty()) {
			mergedList.push_back(numberList1.front());
			numberList1.pop_front();
		}

		if (!numberList2.empty()) {
			mergedList.push_back(numberList2.front());
			numberList2.pop_front();
		}
		

	}
	for (list<int>::iterator it = mergedList.begin(); it != mergedList.end(); ++it)
	{
		cout << *it << " ";
	}

}

void gaussTrick() {
	string numbers;
	getline(cin, numbers);

	stringstream ss(numbers);
	list<int> numberList;

	int num;
	while (ss >> num)
	{
		numberList.push_back(num);
	}

	list<int> resultList;

	list<int>::iterator itBegin = numberList.begin();
	list<int>::iterator itEnd = numberList.end();
	itEnd--;

	while (true)
	{
		if (numberList.size() % 2 == 1) {
			if (itBegin == itEnd) {
				resultList.push_back(*itBegin);
				break;
			}
		}
		else if (numberList.size() / 2 == resultList.size()) {
			break;
		}

		if (numberList.begin() == itEnd || itBegin == itEnd) {
			break;
		}

		resultList.push_back(*itBegin + *itEnd);
		itBegin++;
		itEnd--;
	}

	for (list<int>::iterator it = resultList.begin(); it != resultList.end(); ++it)
	{
		cout << *it << " ";
	}
}

void products() {
	int n;
	cin >> n;
	vector<string> products;
	products.reserve(n);

	for (int i = 0; i < n; i++)
	{
		string product;
		cin >> product;
		products.push_back(product);
	}

	sort(products.begin(), products.end());

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '.' << products[i] << endl;
        sort(products.begin(), products.end());
	}
}

void noNegativeNReverse() {
	string numbers;
	getline(cin, numbers);

	stringstream ss(numbers);
	list<int> numberList;

	int num;
	while (ss >> num)
	{
		numberList.push_back(num);
	}

	for (list<int>::iterator it = numberList.begin(); it != numberList.end(); it++)
	{
		if (*it <= 0) {
			it = numberList.erase(it);
			it--;
		}
	}

	reverse(numberList.begin(), numberList.end());

	if (numberList.empty()) {
		cout << "empty";
	}
	else {
		for (list<int>::iterator it = numberList.begin(); it != numberList.end(); ++it)
		{
			cout << *it << " ";
		}
	}
	
}

int main()
{
	products();

	return 0;
}

