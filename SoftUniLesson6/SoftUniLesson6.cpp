#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void skiTrip() {
	int vacationDays;
	string roomType;
	string feedback;
	double price = 0.0;
	double discount = 0.0;

	cin >> vacationDays;
	cin.ignore(); // To ignore the newline character after the integer input
	getline(cin, roomType);
	getline(cin, feedback);
	if (roomType == "room for one person") {
		price = (vacationDays - 1) * 18;
	}
	else if (roomType == "apartment") {
		if (vacationDays < 10) {
			price = (vacationDays - 1) * 25.0;
			discount = price * 0.30;
		}
		else if (vacationDays >= 10 && vacationDays <= 15) {
			price = (vacationDays - 1) * 25.0;
			discount = price * 0.35;
		}
		else if (vacationDays > 15) {
			price = (vacationDays - 1) * 25.0;
			discount = price * 0.50;
		}
	}
	else if (roomType == "president apartment") {
		if (vacationDays < 10) {
			price = (vacationDays - 1) * 35.0;
			discount = price * 0.10;
		}
		else if (vacationDays >= 10 && vacationDays <= 15) {
			price = (vacationDays - 1) * 35.0;
			discount = price * 0.15;
		}
		else if (vacationDays > 15) {
			price = (vacationDays - 1) * 35.0;
			discount = price * 0.20;
		}
	}

	price -= discount;

	if (feedback == "positive") {
		price += (price * 0.25);
	}
	else if (feedback == "negative") {
		price -= (price * 0.10);
	}

	cout << fixed << setprecision(2) << price;
}

void hotelRoom() {
		
	string month;
	int nights;
	cin >> month >> nights;
	double studioPrice = 0.0;
	double apartmentPrice = 0.0;
	if (month == "May" || month == "October") {
		studioPrice = 50;
		apartmentPrice = 65;
		if (nights > 7 && nights <= 14) {
			studioPrice = studioPrice - (studioPrice * 0.05);
		}
		else if (nights > 14) {
			studioPrice = studioPrice - (studioPrice * 0.30);
		}
	}
	else if (month == "June" || month == "September") {
		studioPrice = 75.20;
		apartmentPrice = 68.70;
		if (nights > 14) {
			studioPrice = studioPrice - (studioPrice * 0.20);
		}
	}
	else if (month == "July" || month == "August") {
		studioPrice = 76;
		apartmentPrice = 77;
	}
	if (nights > 14) {
		apartmentPrice = apartmentPrice - (apartmentPrice * 0.10);
	}
	cout << "Apartment: " << fixed << setprecision(2) << (apartmentPrice * nights) << " lv." << endl;
	cout << "Studio: " << fixed << setprecision(2) << (studioPrice * nights) << " lv.";
}

void operatinsBetweenNumbers() {
		double n1, n2;
		char operation;
		cin >> n1 >> n2 >> operation;
		string evenOrOdd = "";
		if (operation == '+') {
			int result = n1 + n2;
			if (result % 2 == 0) {
				evenOrOdd = "even";
			}
			else {
				evenOrOdd = "odd";
			}
			cout << n1 << " " << operation << " " << n2 << " = " << result << " - " << evenOrOdd;
		}
		else if (operation == '-') {
			int result = n1 - n2;
			if (result % 2 == 0) {
				evenOrOdd = "even";
			}
			else {
				evenOrOdd = "odd";
			}
			cout << n1 << " " << operation << " " << n2 << " = " << result << " - " << evenOrOdd;
		}
		else if (operation == '*') {
			int result = n1 * n2;
			if (result % 2 == 0) {
				evenOrOdd = "even";
			}
			else {
				evenOrOdd = "odd";
			}
			cout << n1 << " " << operation << " " << n2 << " = " << result << " - " << evenOrOdd;
		}
		else if (operation == '/') {
			if (n2 == 0) {
				cout << "Cannot divide " << n1 << " by zero";
			}
			else {
				double result = n1 / n2;
				cout << n1 << " " << operation << " " << n2 << " = " << fixed << setprecision(2) << result;
			}
		}
		else if (operation == '%') {
			if (n2 == 0) {
				cout << "Cannot divide " << n1 << " by zero";
			}
			else {
				int result = static_cast<int>(n1) % static_cast<int>(n2);
				cout << n1 << " " << operation << " " << n2 << " = " << result;
			}
		}
	}

void journey() {
	double budget;
	string season;
	cin >> budget >> season;
	string destination;
	string type;
	double price = 0.0;
	if (budget <= 100) {
		destination = "Bulgaria";
		if (season == "summer") {
			type = "Camp";
			price = budget * 0.30;
		}
		else if (season == "winter") {
			type = "Hotel";
			price = budget * 0.70;
		}
	}
	else if (budget <= 1000) {
		destination = "Balkans";
		if (season == "summer") {
			type = "Camp";
			price = budget * 0.40;
		}
		else if (season == "winter") {
			type = "Hotel";
			price = budget * 0.80;
		}
	}
	else if (budget > 1000) {
		destination = "Europe";
		type = "Hotel";
		price = budget * 0.90;
	}
	cout << "Somewhere in " << destination << endl;
	cout << type << " - " << fixed << setprecision(2) << price << endl;
}

void fishingBoat() {
	int budget;
	string season;
	int countFisherman;
	cin >> budget >> season >> countFisherman;
	double price = 0.0;
	if (season == "Spring") {
		price = 3000;
	}
	else if (season == "Summer" || season == "Autumn") {
		price = 4200;
	}
	else if (season == "Winter") {
		price = 2600;
	}
	if (countFisherman <= 6) {
		price = price - (price * 0.10);
	}
	else if (countFisherman >= 7 && countFisherman <= 11) {
		price = price - (price * 0.15);
	}
	else if (countFisherman >= 12) {
		price = price - (price * 0.25);
	}
	if (countFisherman % 2 == 0 && season != "Autumn") {
		price = price - (price * 0.05);
	}
	if (budget >= price) {
		cout << "Yes! You have " << fixed << setprecision(2) << (budget - price) << " leva left.";
	}
	else {
		cout << "Not enough money! You need " << fixed << setprecision(2) << (price - budget) << " leva.";
	}
}

void newHouse() {
	string typeFlower;
	int countFlowers;
	double budget;

	cin >> typeFlower >> countFlowers >> budget;

	double price = 0.0;

	if (typeFlower == "Roses") {
		price = countFlowers * 5;
		if (countFlowers > 80) {
			price = price - (price * 0.10);
		}
	}
	else if (typeFlower == "Dahlias") {
		price = countFlowers * 3.80;
		if (countFlowers > 90) {
			price = price - (price * 0.15);
		}
	}
	else if (typeFlower == "Tulips") {
		price = countFlowers * 2.80;
		if (countFlowers > 80) {
			price = price - (price * 0.15);
		}
	}
	else if (typeFlower == "Narcissus") {
		price = countFlowers * 3;
		if (countFlowers < 120) {
			price = price + (price * 0.15);
		}
	}
	else if (typeFlower == "Gladiolus") {
		price = countFlowers * 2.50;
		if (countFlowers < 80) {
			price = price + (price * 0.20);
		}
	}

	if (budget >= price) {
		cout << "Hey, you have a great garden with " << countFlowers << " " << typeFlower << " and " << fixed << setprecision(2) << (budget - price) << " leva left.";
	}
	else {
		cout << "Not enough money, you need " << fixed << setprecision(2) << (price - budget) << " leva more.";
	}
}

void summerOutfit() {
	int degrees;
	string timeOfDay;

	cin >> degrees >> timeOfDay;

	string outfit;
	string shoes;

	if (degrees >= 10 && degrees <= 18) {
		if (timeOfDay == "Morning") {
			outfit = "Sweatshirt";
			shoes = "Sneakers";
		}
		else if (timeOfDay == "Afternoon" || timeOfDay == "Evening") {
			outfit = "Shirt";
			shoes = "Moccasins";
		}
	}
	else if (degrees > 18 && degrees <= 24) {
		if (timeOfDay == "Morning" || timeOfDay == "Evening") {
			outfit = "Shirt";
			shoes = "Moccasins";
		}
		else if (timeOfDay == "Afternoon") {
			outfit = "T-Shirt";
			shoes = "Sandals";
		}
	}
	else if (degrees >= 25) {
		if (timeOfDay == "Morning") {
			outfit = "T-Shirt";
			shoes = "Sandals";
		}
		else if (timeOfDay == "Afternoon") {
			outfit = "Swim Suit";
			shoes = "Barefoot";
		}
		else if (timeOfDay == "Evening") {
			outfit = "Shirt";
			shoes = "Moccasins";
		}
	}

	cout << "It's " << degrees << " degrees, get your " << outfit << " and " << shoes << ".";

}

void cinema() {
	string type;
	int rows, cols;
	double cost = 0.0;
	
	cin >> type >> rows >> cols;


	if (type == "Premiere") {
		cost = (rows * cols) * 12;
	}
	else if (type == "Normal") {
		cost = (rows * cols) * 7.50;
	}
	else if (type == "Discount") {
		cost = (rows * cols) * 5;
	}
	
	cout << fixed << setprecision(2) << cost << " leva";
}

int main()
{
	skiTrip();
}

