#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

void reverseString() {
    string input;
    getline(cin, input);
    stack<char> charStack;
    for (char c : input) {
        charStack.push(c);
    }
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
	cout << endl;
}

void stackSum() {
    stack<int> numbers;
    string line;
	getline(cin, line);
	istringstream iss(line);

    while(iss >> line) {
        numbers.push(stoi(line));
	}

    while (cin >> line && line != "end") {
        if (line == "add") {
            int x, y;
			cin >> x >> y;
            numbers.push(x);
			numbers.push(y);
        }else if (line == "remove") {
            int x;
			cin >> x;
            if (x > numbers.size()) {
                continue;
            }
            else {
                while (x--) {
                    numbers.pop();
                }
            }
        }
    }
	int sum = 0;
    while (!numbers.empty()) {
		sum += numbers.top();
		numbers.pop();
    }

	cout << sum << endl;
    
}

void simpleCalc() {
	stack<int> numbers;
	stack<char> operations;
    int sum = 0;

    string line;
	getline(cin, line);
    istringstream iss(line);

	int counter = 1;
    while (iss >> line) {
        if(counter % 2 == 1) {
            numbers.push(stoi(line));
		}
        else {
            operations.push(line[0]);
        }

        counter++;
    }

    while (!operations.empty() || !numbers.empty()) {
        int num1 = numbers.top();
        numbers.pop();
        int num2 = numbers.top();
        numbers.pop();
        char op = operations.top();
        operations.pop();
        if (op == '+') {
            numbers.push(num1 + num2);
        } else if (op == '-') {
            numbers.push(num1 - num2);
        } else if (op == '*') {
            numbers.push(num1 * num2);
        } else if (op == '/') {
            numbers.push(num1 / num2);
            
        }
        if (numbers.size() == 1) {
            break;
        }
	}
	sum = numbers.top();
	cout << sum << endl;
}

void matchingBrackets() {
	stack<int> brackets;
	string line;
	getline(cin, line);

    for (int i = 0; i < line.length();i++) {
        if (line[i] == '(') {
            brackets.push(i);
        }
        else if (line[i] == ')') {
            if (!brackets.empty()) {
                int start = brackets.top();
                brackets.pop();
                cout << line.substr(start, i - start + 1) << endl;
            }
        }
    }

}

void printEvenNumbers() {
    queue<int> numbers;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> line) {
        numbers.push(stoi(line));
    }
    while (!numbers.empty()) {
        int num = numbers.front();
        numbers.pop();
        if (num % 2 == 0) {
            if(numbers.size() > 0) {
                cout << num << ", ";
            } else {
                cout << num;
			}
        }
    }
    cout << endl;
}

void superMarket() {
	queue<string> customers;
	string input;
    while (cin >> input && input != "End") {
        if(input == "Paid") {
            while (!customers.empty()) {
                cout << customers.front() << endl;
                customers.pop();
            }
        }
        else
        {
            customers.push(input);
        }
    }

	cout << customers.size() << " people remaining." << endl;

}

void hotPatoto() {
    queue<string> players;

    string line;
    getline(cin, line);
    istringstream istr(line);
    string player;
    while (istr >> player)
        players.push(player);

    int tosses;
    cin >> tosses;

    int remainingTosses = tosses;
    while (players.size() > 1) {
        string curPlayer = players.front();
        players.pop();
        remainingTosses--;

        if (remainingTosses == 0) {
            cout << "Removed " << curPlayer << endl;
            remainingTosses = tosses;
        }
        else
            players.push(curPlayer);
    }

    cout << "Last is " << players.front() << endl;

}

int main()
{
    hotPatoto();
}

