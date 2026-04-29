#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void cinemaTickets() {

	int total_tickets = 0, student_tickets = 0, standard_tickets = 0, kid_tickets = 0;
	string movie_name;

	while (true) {
		getline(cin, movie_name);
		if (movie_name == "Finish") break;

		int free_seats, sold_tickets = 0;
		cin >> free_seats;
		cin.ignore();

		while (sold_tickets < free_seats) {
			string ticket_type;
			getline(cin, ticket_type);
			if (ticket_type == "End") break;

			total_tickets++;
			sold_tickets++;

			if (ticket_type == "student") student_tickets++;
			else if (ticket_type == "standard") standard_tickets++;
			else if (ticket_type == "kid") kid_tickets++;
		}

		double hall_fullness = (sold_tickets / (double)free_seats) * 100;
		cout << movie_name << " - " << fixed << setprecision(2) << hall_fullness << "% full." << endl;
	}

	double student_percent = total_tickets > 0 ? (student_tickets / (double)total_tickets) * 100 : 0;
	double standard_percent = total_tickets > 0 ? (standard_tickets / (double)total_tickets) * 100 : 0;
	double kid_percent = total_tickets > 0 ? (kid_tickets / (double)total_tickets) * 100 : 0;

	cout << "Total tickets: " << total_tickets << endl;
	cout << fixed << setprecision(2);
	cout << student_percent << "% student tickets." << endl;
	cout << standard_percent << "% standard tickets." << endl;
	cout << kid_percent << "% kids tickets." << endl;

}

void specialNumbers() {
	int n;
	cin >> n;

	for (int i = 1111; i <= 9999; i++) {

		int currentNumber = i;
		bool isSpecial = true;

		while (currentNumber > 0) {

			int digit = currentNumber % 10;
			currentNumber /= 10;

			if (digit == 0 || n % digit != 0) {
				isSpecial = false;
				break;
			}

		}
		if (isSpecial) {
			cout << i << " ";
		}
	}
}

void trainTheTrainers() {
	int juryCount, presentainonCount = 0;
	double totalGrade = 0;
	double overallGrade = 0;
	string presentaionName;
	cin >> juryCount;

	while (getline(cin >> ws,presentaionName) && presentaionName != "Finish") {
		for (int i = 0; i < juryCount; i++) {
			double grade;
			cin >> grade;
			totalGrade += grade;
		}
		overallGrade += totalGrade;
		double averageGrade = totalGrade / juryCount;
		totalGrade = 0;
		cout << presentaionName << " - " << fixed << setprecision(2) << averageGrade << "." << endl;

		presentainonCount++;
	}

	cout << "Student's final assessment is " << fixed << setprecision(2) << (overallGrade / (presentainonCount * juryCount)) << "." << endl;

}

void sumPrime() {
	string command;
	int number;
	int sum = 0;
	int nonPrimeSum = 0;
	
	while (cin >> command && command != "stop") {
		number = stoi(command);
		bool isPrime = true;

		if (number < 0) {
			cout << "Number is negative." << endl;
			continue;
		}
		else
		{
			for (int i = 2; i <= number / 2; i++) {
				if (number % i == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				
				sum += number;
			}
			else {
				nonPrimeSum += number;
			}
		}
		
	}
	cout << "Sum of all prime numbers is: " << sum << endl;
	cout << "Sum of all non prime numbers is: " << nonPrimeSum << endl;
}

void equalSumsEvenOddPosition() {
	int start, end;
	cin >> start >> end;

	for (int i = start; i <= end; i++) {

		int currentNumber = i;
		int evenSum = 0, oddSum = 0;
		int position = 1;

		while (currentNumber > 0) {

			int digit = currentNumber % 10;
			currentNumber /= 10;

			if (position % 2 == 0) {
				evenSum += digit;
			}
			else {
				oddSum += digit;
			}
			position++;
		}

		if (evenSum == oddSum) {
			cout << i << " ";
		}
	}
}

void numberPyramid() {
	int n;
	cin >> n;

	int currentNumber = 1, rows = 1;
	bool isBigger = false;

	while (currentNumber <= n) {
		for (int j = 1; j <= rows; j++) {
			if (currentNumber > n) {
				isBigger = true;
				break;
			}
			else {
				cout << currentNumber++ << " ";
				
			}
		}
		if (isBigger) {
			break;
		}
		else {
			cout << endl;
			rows++;
		}
	}
	
}

int main()
{
	cinemaTickets();
	return 0;
}

