#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

void graduation() {
	string name;
	cin >> name;

	double grade = 0;
	int counter = 1;
	bool failed = false;

	cout.setf(ios::fixed);
	cout.precision(2);

	while (counter <= 12)
	{
		double currentGrade;
		cin >> currentGrade;

		if (currentGrade >= 4.00)
		{
			grade += currentGrade;
		}
		else if (failed)
		{
			cout << name << " has been excluded at " << counter << " grade" << endl;
			break;
		}
		else
		{
			failed = true;
			continue;
		}
		counter++;
	}

	if (counter >= 11) {
		cout << name << " graduated. Average grade: " << grade / 12 << endl;
	}

}

void minNmber() {
	string input;
	int minNumber = INT_MAX;
	int num;

	while (cin >> num)
	{
		if (num < minNumber)
		{
			minNumber = num;
		}
	}
	cout << minNumber << endl;

}

void maxNmber() {
	string input;
	int maxNumber = INT_MIN;
	int num;

	while (cin >> num)
	{
		if (num > maxNumber)
		{
			maxNumber = num;
		}
	}
	cout << maxNumber << endl;

}

void accountBalance() {
	double balance = 0;
	string deposit;

	cout.setf(ios::fixed);
	cout.precision(2);

	while (cin >> deposit && deposit != "NoMoreMoney")
	{
		double amount = stod(deposit);
		if (amount < 0)
		{
			cout << "Invalid operation!" << endl;
			break;
		}

		balance += amount;
		cout << "Increase: " << amount << endl;
	}
	cout << "Total: " << balance << endl;	
}

void Sequence2k() {
	int n;
	cin >> n;
	int number = 1;

	while (number <= n)
	{
		cout << number << endl;
		number = number * 2 + 1;
	}
}

void sumNumbers() {
	int maxSum;
	cin >> maxSum;
	int sum = 0;

	while (true)
	{
		int number;
		cin >> number;
		sum += number;
		if (sum >= maxSum)
		{
			cout << sum << endl;
			break;
		}
	}

	
	
}

void passwordGuess() {
	string password, guess, username;
	cin >> username >> password;

	while (true)
	{
		cin >> guess;
		if (guess == password)
		{
			cout << "Welcome " << username << "!" << endl;
			break;
		}
	}
}

void readText() {
	string word;
	bool work = true;

	while (work)
	{
		cin >> word;
		if (word == "Stop")
		{
			work = false;
			break;
		}
		cout << word << endl;
	}
}

int main()
{
	graduation();
}

