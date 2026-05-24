#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;
bool getDigit(int n, int& single) {
	single = n % 10;
	
	return single % 2 == 0;

}



void centerPoint() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2 && y1 == y2) {
		cout << '(' << x1 << ", " << y1 << ')';
	}

	double distance1 = sqrt(pow(x1, 2) + pow(y1, 2));
	double distance2 = sqrt(pow(x2, 2) + pow(y2, 2));

	if (distance1 < distance2) {
		cout << '(' << x1 << ", " << y1 << ')';
	}
	else if(distance2 < distance1) {
		cout << '(' << x2 << ", " << y2 << ')';
	}
	
	
}

void operations() {
	int a, b;
	char operation;
	cin >> a >> b >> operation;

	switch (operation) {
		case '+':
			cout << a + b;
			break;
		case '*':
			cout << a * b;
			break;
		case '-':
			cout << a - b;
			break;
		case '/':
			cout << a / b;
			break;
	}
}

void factorialDivision() {
	int a, b;
	cin >> a >> b;
	double aF = 1.0;
	double bF = 1.0;
	for (int i = 1; i <= a; i++) {
		aF *= i;
	}
	for (int i = 1; i <= b; i++) {
		bF *= i;
	}


	cout << fixed << setprecision(2) << aF / bF;
}

void nameOfNumbers() {
	int n;
	string result;
	cin >> n;

	if (n == 0) {
		cout << "zero";
		return;
	}
	

	int n1 = n % 10;
	int n2 = (n / 10) % 10;
	int n3 = (n / 100) % 10;
	int n4 = (n / 1000) % 10;

	switch (n4) {
		case 1:
			result += "one thousand ";
			break;
		case 2:
			result += "two thousand ";
			break;
		case 3:
			cout << "three thousand ";
			break;
		case 4:
			cout << "four thousand ";
			break;
		case 5:
			cout << "five thousand ";
			break;
		case 6:
			cout << "six thousand ";
			break;
		case 7:
			cout << "seven thousand ";
			break;
		case 8:
			cout << "eight thousand ";
			break;
		case 9:
			cout << "nine thousand ";
			break;
		}

	switch (n3) {
		case 1:
			result += "one hundred ";
			break;
		case 2:
			result += "two hundred ";
			break;
		case 3:
			result += "three hundred ";
			break;
		case 4:
			result += "four hundred ";
			break;
		case 5:
			result += "five hundred ";
			break;
		case 6:
			result += "six hundred ";
			break;
		case 7:
			result += "seven hundred ";
			break;
		case 8:
			result += "eight hundred ";
			break;
		case 9:
			result += "nine hundred ";
			break;
	}

	if (n2 > 1) {
		switch (n2)
		{
		case 2:
			result += "twenty ";
			break;
		case 3:
			result += "thirty ";
			break;
		case 4:
			result += "forty ";
			break;
		case 5:
			result += "fifty ";
			break;
		case 6:
			result += "sixty ";
			break;
		case 7:
			result += "seventy ";
			break;
		case 8:
			result += "eighty ";
			break;
		case 9:
			result += "ninety ";
			break;
		}
	}
	else if (n2 == 1)
	{
		switch (n2)
		{
		case 1:
			switch (n1)
			{
			case 1:
				result += "eleven";
				break;
			case 2:
				result += "twelve";
				break;
			case 3:
				result += "thirteen";
				break;
			case 4:
				result += "fourteen";
				break;
			case 5:
				result += "fifteen";
				break;
			case 6:
				result += "sixteen";
				break;
			case 7:
				result += "seventeen";
				break;
			case 8:
				result += "eighteen";
				break;
			case 9:
				result += "nineteen";
				break;
			}
		}
	}

	if (n2 > 1 || n2 == 0) {
		switch (n1)
		{
		case 1:
			result += "one";
			break;
		case 2:
			result += "two";
			break;
		case 3:
			result += "three";
			break;
		case 4:
			result += "four";
			break;
		case 5:
			result += "five";
			break;
		case 6:
			result += "six";
			break;
		case 7:
			result += "seven";
			break;
		case 8:
			result += "eight";
			break;
		case 9:
			result += "nine";
			break;
		}
	}
	

	

	cout << result << endl;
}

void multiplyEvensSumByOdds() {
	int n;
	cin >> n;

	int evenSum = 0;
	int oddSum = 0;
	while (n) {
		int single;

		if (getDigit(n, single)) {
			evenSum += single;
		}
		else {
			oddSum += single;
		}
		n /= 10;
	}

	cout << evenSum * oddSum << endl;
	
} 

int checkHowManyVowelsInAWord(string word)
{
	int vowelCount = 0;

	for (int i = 0; word[i] != '\0'; ++i) {
		if (word[i] == 'a' || word[i] == 'e'
			|| word[i] == 'i' || word[i] == 'o'
			|| word[i] == 'u' || word[i] == 'A'
			|| word[i] == 'E' || word[i] == 'I'
			|| word[i] == 'O' || word[i] == 'U') {
			++vowelCount;
		}
	}
	return vowelCount;
}

void passValid() {
	string pass;
	string result;
	int digits = 0;
	bool between6and10 = false, onlyLettersAndDigits = false, atLeast2Digits = false;

	cin >> pass;
	int passSize = pass.length();

	if (passSize < 6 && passSize <= 10) {
		between6and10 = true;
	}
	for (int i = 0; i < pass.length(); i++) {
		if (!isalnum(pass[i])) {
			onlyLettersAndDigits = true;
		}
		if (isdigit(pass[i])) {
			digits++;
		}
	}
	if (digits < 2) {
		atLeast2Digits = true;
	}
	if (between6and10)
	{
		result += "Password must be between 6 and 10 characters\n";
	}if (onlyLettersAndDigits)
	{
		result += "Password must consist only of letters and digits\n";
	}
	if (atLeast2Digits)
	{
		result += "Password must have at least 2 digits\n";
	}
	if (atLeast2Digits == false && onlyLettersAndDigits == false && between6and10 == false) {
		result += "Password is valid\n";
	}
	cout << result;
}

double orders(string product,int quantity) {
	double price = 0.0;
	double result = 0.0;

	if (product == "coffee") {
		price = 1.50;
	}
	else if (product == "water") {
		price = 1.00;
	}
	else if (product == "coke") {
		price = 1.40;
	}
	else if (product == "snacks") {
		price = 2.00;
	}
	result = price * quantity;

	return result;
}

void greaterOfTwoValues() {
	string type;
	getline(cin, type);
	if (type == "int")
	{
		int a, b;
		cin >> a >> b;

		if (a > b) {
			cout << a;
		}
		else {
			cout << b;
		}
	}
	else if (type == "char")
	{
		char a, b;
		cin >> a >> b;

		if (a > b) {
			cout << a;
		}
		else {
			cout << b;
		}
	}
	else if (type == "string")
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);
		if (a > b) {
			cout << a;
		}
		else {
			cout << b;
		}
	}
	
}

int main()
{
	greaterOfTwoValues();
}


