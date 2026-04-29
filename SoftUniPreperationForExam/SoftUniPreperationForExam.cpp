#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

using namespace std;

void vetenarianParking() {
	int days, hoursInTheParkingLot;
	cin >> days >> hoursInTheParkingLot;
	double totalSum = 0, dailySum = 0;

	for (int i = 1; i <= days; i++) {
		double dailySum = 0;
		for(int hours = 1; hours <= hoursInTheParkingLot; hours++)
		{
			if (i % 2 == 0 && hours % 2 != 0) {
				dailySum += 2.50;
			}
			else if (i % 2 != 0 && hours % 2 == 0) {
				dailySum += 1.25;
			}
			else {
				dailySum += 1.00;
			}

		}
		totalSum += dailySum;
		cout << fixed << setprecision(2) << "Day: " << i << " - " << dailySum << " leva" << endl;
	}
	cout << "Total: " << fixed << setprecision(2) << totalSum << " leva" << endl;
}

void touristShop() {
	double budget;
	cin >> budget;

	string command;
	double sum = 0;
	int products = 0;

	while (getline(cin >> ws, command) && command != "Stop") {
		double price;
		cin >> price;

		products++;

		if (products % 3 == 0) {
			price /= 2;
		}
		if (price > budget) {
			cout << "You don't have enough money!" << endl;
			cout << "You need " << fixed << setprecision(2) << price - budget << " leva!" << endl;
			return;
		}
		budget -= price;
		sum += price;

	}
	cout << "You bought " << products << " products for " << fixed << setprecision(2) << sum << " leva." << endl;
}

void movieRating() {
	int movies;
	cin >> movies;

	string bestMovie;
	double bestRating = DBL_MIN;
	string worstMovie;
	double worstRating = DBL_MAX;
	double allMoviesRating = 0;

	for (int i = 0; i < movies; i++) {
		string movieName;
		double rating;

		getline(cin >> ws, movieName);
		cin >> rating;

		allMoviesRating += rating;

		if (rating > bestRating) {
			bestRating = rating;
			bestMovie = movieName;
		}
		if (rating < worstRating) {
			worstRating = rating;
			worstMovie = movieName;
		}
	}

	cout << bestMovie << " is with highest rating: " << fixed << setprecision(1) << bestRating << endl;
	cout << worstMovie << " is with lowest rating: " << fixed << setprecision(1) << worstRating << endl;
	cout << "Average rating: " << fixed << setprecision(1) << allMoviesRating / movies << endl;
}

void artGymnastics() {
	string country, tool;
	cin >> country >> tool;

	double difficulty = 0;
	double performance = 0;

	if (country == "Russia") {
		if (tool == "ribbon") {
			difficulty = 9.1;
			performance = 9.4;
		}
		else if (tool == "hoop") {
			difficulty = 9.3;
			performance = 9.8;
		}
		else if (tool == "rope") {
			difficulty = 9.6;
			performance = 9.0;
		}
	}
	else if (country == "Bulgaria") {
		if (tool == "ribbon") {
			difficulty = 9.6;
			performance = 9.4;
		}
		else if (tool == "hoop") {
			difficulty = 9.55;
			performance = 9.75;
		}
		else if (tool == "rope") {
			difficulty = 9.5;
			performance = 9.4;
		}
	}
	else if (country == "Italy") {
		if (tool == "ribbon") {
			difficulty = 9.2;
			performance = 9.5;
		}
		else if (tool == "hoop") {
			difficulty = 9.45;
			performance = 9.35;
		}
		else if (tool == "rope") {
			difficulty = 9.7;
			performance = 9.15;
		}
	}
	double totalPoints = difficulty + performance;
	double percent = ((20 - totalPoints) / 20) * 100;
	cout << "The team of " << country << " get " << fixed << setprecision(3) << totalPoints << " on " << tool << "." << endl;
	cout << fixed << setprecision(2) << percent << "%" << endl;
}

void familyVacatio() {
	int nights, additionalExpenses;
	double pricePerNight, budget;
	cin >> budget >> nights;

	cin >> pricePerNight >> additionalExpenses;

	double priceForNights = nights * pricePerNight;
	double additionalExpensesPercent = budget * (additionalExpenses / 100.0);
	double totalExpenses = priceForNights + additionalExpensesPercent;

	if (nights > 7) {
		totalExpenses -= priceForNights * 0.05;
	}
	if (budget >= totalExpenses) {
		cout << "Ivanovi will be left with " << fixed << setprecision(2) << budget - totalExpenses << " leva after vacation." << endl;
	}
	else {
		cout << fixed << setprecision(2) << totalExpenses - budget << " leva needed." << endl;
	}
}

void movieProfit() {
	string movieName;

	getline(cin >> ws, movieName);

	int days;
	double ticketsSold, ticketPrice, cinemaCut;

	cin >> days >> ticketsSold >> ticketPrice >> cinemaCut;

	double profitBeforeCinemaCut = days * ticketsSold * ticketPrice;
	double CinemaCut = profitBeforeCinemaCut * (cinemaCut / 100);
	double profitAfterCinemaCut = profitBeforeCinemaCut - CinemaCut;

	cout << "The profit from the movie " << movieName << " is " << fixed<< setprecision(2) << profitAfterCinemaCut << " lv." << endl;
}

int main()
{
	vetenarianParking();
}

