#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void signOfIntegerNumbers() {
	int n;
	cin >> n;

	if (n > 0) {
		cout << "The number "<< n <<" is positive.";
	}
	else if (n < 0) {
		cout << "The number " << n << " is negative.";
	}
	else {
		cout << "The number " << n << " is zero.";
	}
}

void grades() {
	double grade;
	string result;
	cin >> grade;

	if (grade >= 2.0 && grade <= 2.99)
	{
		result = "Fail";
	}
	else if (grade >= 3.0 && grade <= 3.49)
	{
		result = "Poor";
	}
	else if (grade >= 3.50 && grade <= 4.49)
	{
		result = "Good";
	}
	else if (grade >= 4.50 && grade <= 5.49)
	{
		result = "Very good";
	}
	else if (grade >= 5.50 && grade <= 6.00)
	{
		result = "Excellent";
	}

	cout << result << endl;
}

void smallestOfThreeNumbers() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b && a < c) {
		cout << a;
	}
	else if (b < a && b < c) {
		cout << b;
	}
	else {
		cout << c;
	}
}

void printingTriangle() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
}

int calculateRectangleArea(int a, int b) {
	return a * b;
}

int mathPower(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int main()
{
	int a, b;
	cin >> a >> b;

	cout << mathPower(a, b) << endl;
	
	return 0;
}

