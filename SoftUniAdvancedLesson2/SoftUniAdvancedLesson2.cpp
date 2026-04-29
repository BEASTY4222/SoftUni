#include <iostream>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int minElem(stack<int> numbers) {
	int smallest = INT_MAX;
	while (!numbers.empty())
	{
		if (numbers.top() < smallest) {
			smallest = numbers.top();
		}

		numbers.pop();
	}

	return smallest;
}
int maxElement(stack<int> numbers) {
	int largest = INT_MIN;
	while (!numbers.empty())
	{
		if (numbers.top() > largest) {
			largest = numbers.top();
		}
		numbers.pop();
	}
	return largest;
}

void BSO() {
    int n, s, x;
	cin >> n >> s >> x;

	stack<int> numbers;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push(temp);
	}

	while (s--) {
		numbers.pop();
	}

	if (numbers.empty()) {
		cout << 0;
		return;
	}

	int smallest = INT_MAX;

	while (!numbers.empty())
	{
		if (x == numbers.top()) {
			cout << "true";
			return;
		}
		else if (numbers.top() < smallest) {
			smallest = numbers.top();
		}

		numbers.pop();
	}

	cout << smallest;

}

void BQO() {
	int n, s, x;
	cin >> n >> s >> x;

	queue<int> numbers;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push(temp);
	}

	while (s--) {
		numbers.pop();
	}

	if (numbers.empty()) {
		cout << 0;
		return;
	}

	int smallest = INT_MAX;

	while (!numbers.empty())
	{
		if (x == numbers.front()) {
			cout << "true";
			return;
		}
		else if (numbers.front() < smallest) {
			smallest = numbers.front();
		}

		numbers.pop();
	}

	cout << smallest;

}

void MINAndMAX() {
	stack<int> numbers;
	int numberOfCommands,command, number;
	cin >> numberOfCommands;
	while (numberOfCommands--)
	{
		cin >> command;
		switch (command)
		{
			case 1:
				cin >> number;
				numbers.push(number);
				break;
			case 2:
				if (numbers.empty())
				{

				}
				else {
					numbers.pop();
				}
				break;
			case 3:
				cout << maxElement(numbers) << endl;
				break;
			case 4:
				cout << minElem(numbers) << endl;
				break;
		}
	}

	while (!numbers.empty())
	{
		if (numbers.size() == 1) {
			cout << numbers.top();
		}
		else {
			cout << numbers.top() << ", ";
		}
		
		numbers.pop();
	}
	
	
}

void fastFoodChain() {
	int allFood, order;
	cin >> allFood;
	queue<int> orders;

	cin.ignore();

	string ordersLineS;
	getline(cin, ordersLineS);
	istringstream buffer(ordersLineS);
	
	while (buffer >> order) {
		orders.push(order);
	}

	int biggestOrder = INT_MIN;

	while (!orders.empty()) {
		int currentOrder = orders.front();
		
		if (currentOrder > biggestOrder) {
			biggestOrder = currentOrder;
		}

		if (allFood - currentOrder <= 0)
		{
			cout << biggestOrder << endl;
			cout << "Orders left: ";
			while (!orders.empty()) {
				cout << orders.front() << " ";
				orders.pop();
			}
			return;
		}
		else {
			allFood -= currentOrder;
			orders.pop();
		}

	}

	cout << biggestOrder << endl;
	cout << "Orders complete";
	
}

void fashionBotique() {
	int rackCapacity, clothes;
	stack<int> clothesStack;

	string clothesLineS;
	getline(cin, clothesLineS);
	cin >> rackCapacity;
	cin.ignore();
	stringstream clothesLine(clothesLineS);
	
	while (clothesLine >> clothes) {
		clothesStack.push(clothes);
	}
	
	int numberOfRacks = 1;
	int currentRack = 0;
	while (!clothesStack.empty()) {
		if (currentRack + clothesStack.top() > rackCapacity){
			currentRack = 0;
			numberOfRacks++;
		}
		else {
			currentRack += clothesStack.top();
		}
		
		clothesStack.pop();
	}

	if (currentRack > 0) {
		numberOfRacks++;
	}

	cout << numberOfRacks << endl;
}

void truckTour() {
	int n, indexToStart = 0;
	cin >> n;
	queue<int> amountOfPetrol, distanceToNextPump;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		amountOfPetrol.push(temp);
		cin >> temp;
		distanceToNextPump.push(temp);
	}
	
	while (!amountOfPetrol.empty())
	{
		if (amountOfPetrol.front() < distanceToNextPump.front()) {
			indexToStart++;
	
			amountOfPetrol.push(amountOfPetrol.front());
			amountOfPetrol.pop();
			distanceToNextPump.push(distanceToNextPump.front());
			distanceToNextPump.pop();
		}
		else
		{
			cout << indexToStart << endl;
			return;
		}
	}
}

void balancedParentheses() {
	string line;
	getline(cin, line);
	istringstream mainLine(line);

	stack<char> openBrackets;
	char c;

	while(mainLine >> c){
		switch (c)
		{
		case '{':
		case '[':
		case '(':
			openBrackets.push(c);
			break;
		case '}':
			if (!openBrackets.empty() && openBrackets.top() == '{') {
				openBrackets.pop();
			}
			else {
				cout << "NO";
				return;
			}
			break;
		case ']':
			if (!openBrackets.empty() && openBrackets.top() == '[') {
				openBrackets.pop();
			}
			else {
				cout << "NO";
				return;
			}
			break;
		case ')':
			if (!openBrackets.empty() && openBrackets.top() == '(') {
				openBrackets.pop();
			}
			else {
				cout << "NO";
				return;
			}
			break;
		}
	}

	cout << "YES";
}


int main()
{
	balancedParentheses();
}
