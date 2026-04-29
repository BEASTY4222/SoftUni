#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

void oddEvenSum() {
	int n;
	cin >> n;

	int oddSum = 0;
	int evenSum = 0;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;

		if (i % 2 == 0) {
			evenSum += number;
		}else {
			oddSum += number;
		}
	}

	if (oddSum == evenSum) {
		cout << "Yes" << endl;
		cout << "Sum = " << oddSum << endl;
	}else {
		cout << "No" << endl;
		cout << "Diff = " << abs(oddSum - evenSum) << endl;
	}
}

void leftAndRightSum() {
	int n;
	cin >> n;

	int leftSum = 0;
	int rightSum = 0;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		leftSum += number;
	}

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		rightSum += number;
	}

	if (leftSum == rightSum) {
		cout << "Yes, sum = " << leftSum << endl;
	}
	else {
		cout << "No, diff = " << abs(leftSum - rightSum) << endl;
	}
}

void numberSequence() {
	int n;
	cin >> n;

	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (number > max) {
			max = number;
		}
		if (number < min) {
			min = number;
		}
	}

	cout << "Max number: " << max << endl;
	cout << "Min number: " << min << endl;
}

void sumOfNumbers() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		sum += number;
	}
	cout << sum << endl;
}

void vowelsSum() {
	string word;
	getline(cin, word);
	int sum = 0;
	for (int i = 0; i < word.size(); i++) {
		switch (word[i]) {
		case 'a':
			sum += 1;
			break;
		case 'e':
			sum += 2;
			break;
		case 'i':
			sum += 3;
			break;
		case 'o':
			sum += 4;
			break;
		case 'u':
			sum += 5;
			break;
		}
	}
	cout << sum << endl;
}

void symbolStream() {
	string word;
    getline(cin, word);

	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << endl;
	}
}

void evenPowersOf2() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i += 2) {
		cout << pow(2, i) << endl;
	}
}

void numbersOneToNumberWithStep3() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i += 3) {
		cout << i << endl;
	}
}

void fromNumberToOne() {
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		cout << i << endl;
	}
}

void numberOneToOneHundred() {
	for (int i = 1; i <= 100; i++) {
		cout << i << endl;
	}
}

int main()
{
	for (int i = 7; i < 1000; i += 10) {
		cout << i << " ";
	}
}

