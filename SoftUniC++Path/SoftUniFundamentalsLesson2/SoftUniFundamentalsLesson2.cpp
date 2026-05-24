#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <climits>
#include <utility>

using namespace std;

void strongNumber() {
	int n;
	cin >> n;

	int sum = 0;
	int originalN = n;

	while (n > 0) {
		int digit = n % 10;
		int factorial = 1;
		for (int i = 1; i <= digit; i++) {
			factorial *= i;
		}
		sum += factorial;
		n /= 10;
	}
	if (sum == originalN) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

void printAndSum() {
	int minN,maxN;
	cin >> minN >> maxN;
	int sum = 0;

	for (int i = minN; i <= maxN; i++) {
		cout << i << " ";
		sum += i;
	}
	cout << endl << "Sum: " << sum << endl;
}

void greatestCommonDivisor() {
	int a, b;
	cin >> a >> b;

	// gcd(a, b) another method
	// Euclidean algorithm
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	cout << a << endl;
}

void minMax() {
	int n;
	cin >> n;

	int minNum = INT_MAX;
	int maxNum = INT_MIN;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		 
		if (num < minNum) {
			minNum = num;
		}
		if (num > maxNum) {
			maxNum = num;
		}
	}
	cout << minNum << " " << maxNum << endl;
}

void numbersToN() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
}

void quadraticEquation() {
	double a, b, c;
	cin >> a >> b >> c;

	double D = b * b - 4 * a * c;
	if (D > 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	}
	else if (D == 0) {
		double x = -b / (2 * a);
		cout << x << endl;
	}
	else {
		cout << "no roots" << endl;
	}
}

void productSing() {
	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	int i = 0;
	if (num1 <= 0)
		i++;
	if (num2 <= 0)
		i++;
	if (num3 <= 0)
		i++;

	if (i == 2)
	{
		cout << "+" << endl;
	}else if(num1 == 0 || num2 == 0 || num3 == 0 ) {
		cout << "+" << endl;
	}
	else
		cout << "-" << endl;
}

void orderTwoNums() {
	long int number1, number2;
	cin >> number1 >> number2;

	if (number1 < number2) {
		cout << number1 << " " << number2 << endl;
	}
	else if (number1 > number2) {
		cout << number2 << " " << number1 << endl;
	}
	else 
		cout <<  number1 << " " << number2 << endl;
	
}

int main()
{
	quadraticEquation();
}


