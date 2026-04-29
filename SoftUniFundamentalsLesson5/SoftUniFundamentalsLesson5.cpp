#include <iostream>
#include <array>

using namespace std;

void equalArrays() {
	int n;
	cin >> n;

	array<int, 100> firstArray;
	array<int, 100> secondArray;

	for (int i = 0; i < n; i++)
	{
		cin >> firstArray[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> secondArray[i];
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (firstArray[i] != secondArray[i])
		{
			cout << "Arrays are not identical. Found difference at " << i << " index.";
			return;
		}
		sum += firstArray[i];
	}
	cout << "Arrays are identical. Sum: " << sum;
}

void evenAndOddSubtraction(){
	int n;
	cin >> n;

	array<int, 100> numbers;
	int oddSum = 0;
	int evenSum = 0;
	

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (numbers[i] % 2)
		{
			oddSum += numbers[i];
		}
		else
		{
			evenSum += numbers[i];
		}
	}
	cout << evenSum - oddSum;

}

void reverseAnArrayOfStrings() {
	int n;
	cin >> n;
	array<string, 100> strings;

	for (int i = 0; i < n; i++)
	{
		cin >> strings[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << strings[i] << " ";
	}
}

void sumEvenNumbers() {
	int n;
	cin >> n;

	int numbers[100];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (!(numbers[i] % 2))
		{
			sum += numbers[i];
		}
	}

	cout << sum;
}

void printNumbersInReverseOrder() {
	int n;
	cin >> n;

	array<int, 100> numbers;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cout << numbers[i] << " ";
	}
}

void dayOfWeek() {
	int day;
	cin >> day;
	array<string, 7> days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	if (day < 1 || day > 7) {
		cout << "Invalid day!";
	}
	else {
		cout << days[day - 1];
	}
}

int main()
{
	equalArrays();
	return 0;
}

