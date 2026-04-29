#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void evenNumbers() {
	int n;
	cin >> n;

	while (n % 2 != 0) {
		cout << "Please write an even number." << endl;
		cin >> n;
	}

	cout << "The number is: " << abs(n) << endl;
}

void multiplicationTable() {
	int n;
	cin >> n;

	for (int i = 1; i <= 10; i++) {
		cout << n << " X " << i << " = " << n * i << endl;
	}
}

void sumOfOddNumbers() {
	int n;
	cin >> n;

	int sum = 0;
	int num = 1;

	for (int i = 1; num <= n; i++) {
		if (i % 2 != 0) {
			sum += i;
			cout << i << endl;
			num++;
			
		}
	}
	cout << "Sum: " << sum << endl;
}

void divisibleByThree() {
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			cout << i << endl;
		}
	}
}

void foreingLangueges() {
	string country;
	cin >> country;

	bool english = country == "USA" || country == "England";
	bool spanish = country == "Spain" || country == "Argentina" || country == "Mexico";

	if (english) {
		cout << "English" << endl;
	}
	else if (spanish) {
		cout << "Spanish" << endl;
	}
	else {
		cout << "unknown" << endl;
	}
}

void monthPrinter() {
	int month;
	cin >> month;
	switch (month) {
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "February" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "October" << endl;
		break;
	case 11:
		cout << "November" << endl;
		break;
	case 12:
		cout << "December" << endl;
		break;
	default:
		cout << "Error!" << endl;
	}
}

void passedOrFailed() {
    string result;
    double grade;
    cin >> grade;

    if (grade > 2.99)
        result = "Passed!";
    else
        result = "Failed!";


    cout << result << endl;
}

void studentInformation() {

    string name;
    int age;
    double grade;

    getline(cin, name);

    cin >> age >> grade;

    //Name: John, Age: 15, Grade: 5.40  
    cout << setprecision(2) << fixed;
    cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;

}

int main()
{
	sumOfOddNumbers();
}

