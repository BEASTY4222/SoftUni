#include <iostream>
#include <climits>
#include <iomanip>
#include <string>

using namespace std;

void tennisRangList() {
	int tournaments;
	int startingPoints;
	cin >> tournaments >> startingPoints;

	int wins = 0;
	int seasonPoints = 0;
	for (int i = 0; i < tournaments; i++) {
		string result;
		cin >> result;

		if (result == "W") {
			seasonPoints += 2000;
			wins++;
		}
		else if (result == "F") {
			seasonPoints += 1200;
		}
		else if (result == "SF") {
			seasonPoints += 720;
		}
	}

	cout << "Final points: " << seasonPoints + startingPoints << endl;
	cout << "Average points: " << seasonPoints / tournaments << endl;
	cout << fixed << setprecision(2) << (double)wins / tournaments * 100 << "%" << endl;
}

void trekingMania() {
	int n;
	cin >> n;

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;

	for (int i = 0; i < n; i++) {
		int climbers;
		cin >> climbers;

		if (climbers < 6) {
			p1 += climbers;
		}
		else if (climbers < 13) {
			p2 += climbers;
		}
		else if (climbers < 26) {
			p3 += climbers;
		}
		else if (climbers < 41) {
			p4 += climbers;
		}
		else {
			p5 += climbers;
		}
	}

	int totalClimbers = p1 + p2 + p3 + p4 + p5;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << fixed << setprecision(2) << (double)p1 / totalClimbers * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p2 / totalClimbers * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p3 / totalClimbers * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p4 / totalClimbers * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p5 / totalClimbers * 100 << "%" << endl;
}

void oscars() {
	string actor;
	double points;
	int n;

	getline(cin, actor);
	cin >> points >> n;

	for (int i = 0; i < n && points < 1250.5; i++) {
		string judge;
		double judgePoints;

		getline(cin >> ws, judge);
		cin >> judgePoints;

		points += (judge.length() * judgePoints) / 2;
	}

	if (points > 1250.5) {
		cout << "Congratulations, " << actor << " got a nominee for leading role with " << fixed << setprecision(1) << points << "!";
	}
	else {
		cout << "Sorry, " << actor << " you need " << fixed << setprecision(1) << 1250.5 - points << " more!";
	}
}

void salary() {
	int n;
	cin >> n;

	int salary;
	cin >> salary;

	for (int i = 0; i < n && salary > 0; i++) {
		string site;
		cin >> site;
		if (site == "Facebook") {
			salary -= 150;
		}
		else if (site == "Instagram") {
			salary -= 100;
		}
		else if (site == "Reddit") {
			salary -= 50;
		}
	}

	if (salary > 0) {
		cout << salary << endl;
	}
	else {
		cout << "You have lost your salary." << endl;
	}
}

void cleverLily() {
	int n;
	cin >> n;

	double priceWashingMachine;
	cin >> priceWashingMachine;

	int priceToy;
	cin >> priceToy;

	int savedMoney = 0, giftedMoney = 10;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			savedMoney += giftedMoney - 1;
			giftedMoney += 10;
		}
		else {
			savedMoney += priceToy;
		}
	}

	if (savedMoney >= priceWashingMachine) {
		cout << "Yes! " << fixed << setprecision(2) << savedMoney - priceWashingMachine << endl;
	}
	else {
		cout << "No! " << fixed <<  setprecision(2) << priceWashingMachine - savedMoney << endl;
	}
}

void histogram() {
	int n;
	cin >> n;

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (number < 200) {
			p1++;
		}
		else if (number < 400) {
			p2++;
		}
		else if (number < 600) {
			p3++;
		}
		else if (number < 800) {
			p4++;
		}
		else {
			p5++;
		}
	}

	cout << fixed << setprecision(2) << (double)p1 / n * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p2 / n * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p3 / n * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p4 / n * 100 << "%" << endl;
	cout << fixed << setprecision(2) << (double)p5 / n * 100 << "%" << endl;
}

void halfSumElement() {
	int n, sum = 0, maxNumber = INT_MIN;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;

		sum += number;

		if (number > maxNumber) {
			maxNumber = number;
		}
	}


	if (sum - maxNumber== maxNumber) {
		cout << "Yes" << endl;
		cout << "Sum = " << sum - maxNumber << endl;
	}
	else {
		sum -= maxNumber;
		cout << "No" << endl;
		cout << "Diff = " << abs(maxNumber - sum) << endl;
	}
}

void numbersEndingInSeven() {
	for (int i = 7; i < 1000; i += 10) {
		cout << i << " ";
	}
}

int main()
{
	tennisRangList();
}


