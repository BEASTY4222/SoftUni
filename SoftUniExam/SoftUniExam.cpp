#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;   

void goldMine() {
	int locations;
	cin >> locations;

	for (int i = 0; i < locations; i++) {

		double expectedGoldPerDay;
		cin >> expectedGoldPerDay;
		int days;
		cin >> days;

		double totalGold = 0;
		for (int j = 0; j < days; j++) {
			double goldPerDay;
			cin >> goldPerDay;
			totalGold += goldPerDay;
		}

		double averageGoldPerDay = totalGold / days;

		if (averageGoldPerDay >= expectedGoldPerDay) {
			cout << "Good job! Average gold per day: " << fixed << setprecision(2) << averageGoldPerDay << "." << endl;
		}
		else {
			cout << "You need " << fixed << setprecision(2) << expectedGoldPerDay - averageGoldPerDay << " gold." << endl;
		}
	}
	
	
}

void christmasGifts() {
	const int TOY_PRICE = 5;
	const int SWEATER_PRICE = 15;

	int adults = 0, kids = 0, moneyForToys, moneyForSweaters;

	string command;
	while (cin >> command && command != "Christmas") {
		int age = stoi(command);
		if (age <= 16) {
			kids++;
		}
		else {
			adults++;
		}
	}


	moneyForToys = kids * TOY_PRICE;
	moneyForSweaters = adults * SWEATER_PRICE;

	cout << "Number of adults: " << adults << endl;
	cout << "Number of kids: " << kids << endl;
	cout << "Money for toys: " << moneyForToys << endl;
	cout << "Money for sweaters: " << moneyForSweaters << endl;

}

void catFood() {
	const double CAT_FOOD_PRICE_PER_KILO = 12.45;
	int cats, totalFoodAte = 0, groupOne = 0, groupTwo = 0, groupThree = 0;
	cin >> cats;
	
	for (int i = 0; i < cats; i++) {
		int foodEatenInGrams;
		cin >> foodEatenInGrams;

		totalFoodAte += foodEatenInGrams;

		if (foodEatenInGrams >= 100 && foodEatenInGrams < 200)
		{
			groupOne++;
		}
		else if (foodEatenInGrams >= 200 && foodEatenInGrams < 300)
		{
			groupTwo++;
		}
		else if (foodEatenInGrams >= 300 && foodEatenInGrams < 400)
		{
			groupThree++;
		}
	}
	
	double neededFoodInKilos = totalFoodAte / 1000.0;
	double neededMoney = neededFoodInKilos * CAT_FOOD_PRICE_PER_KILO;
	cout << "Group 1: " << groupOne << " cats." << endl;
	cout << "Group 2: " << groupTwo << " cats." << endl;
	cout << "Group 3: " << groupThree << " cats." << endl;
	cout << "Price for food per day: " << fixed << setprecision(2) << neededMoney << " lv." << endl;

}

void pastryShop() {

	string product;
	int orderedProduct, date;
	cin >> product >> orderedProduct >> date;

	double moneyNeededToPay = 0;

	if (date <= 15) {
		if (product == "Cake") {
			moneyNeededToPay = orderedProduct * 24;
		}
		else if (product == "Souffle") {
			moneyNeededToPay = orderedProduct * 6.66;
		}
		else if (product == "Baklava") {
			moneyNeededToPay = orderedProduct * 12.60;
		}
	}
	else if (date > 15) {
		if (product == "Cake") {
			moneyNeededToPay = orderedProduct * 28.70;
		}
		else if (product == "Souffle") {
			moneyNeededToPay = orderedProduct * 9.80;
		}
		else if (product == "Baklava") {
			moneyNeededToPay = orderedProduct * 16.98;
		}
	}

	if (date <= 22)
	{
		if (moneyNeededToPay > 100 && moneyNeededToPay <= 200) {
			moneyNeededToPay -= moneyNeededToPay * 0.15;
		}
		else if (moneyNeededToPay >= 200) {
			moneyNeededToPay -= moneyNeededToPay * 0.25;
		}
	}


	if (date <= 15) {
		moneyNeededToPay -= moneyNeededToPay * 0.10;
	}

	cout << fixed << setprecision(2) << moneyNeededToPay << endl;
	
}

void procecors() {
	const double PROCESOR_PRICE = 110.10;
	int goalProcessors, employees, workingDays;
	cin >> goalProcessors >> employees >> workingDays;
	
	int totalHours = employees * workingDays * 8;
	int producedProcessors = floor(totalHours / 3);

	if (producedProcessors >= goalProcessors) {
		cout << "Profit: -> " << fixed << setprecision(2) << (producedProcessors - goalProcessors) * PROCESOR_PRICE << " BGN" << endl;
	}
	else {
		cout << "Losses: -> " << fixed << setprecision(2) << (goalProcessors - producedProcessors) * PROCESOR_PRICE << " BGN" << endl;
	}
}

void miningRig() {
	const int videoCards = 13;
	const int trasformers = 13;
	const int otherComponentsPrice = 1000;

	double neededMoney;
	double neededTime;

	int videoCardsPrice;
	cin >> videoCardsPrice;

	int trasnformersPrice;
	cin >> trasnformersPrice;
	
	double videoCardsPowerConsumption;
	cin >> videoCardsPowerConsumption;

	double videoCardProfitPerDay;
	cin >> videoCardProfitPerDay;


	

	double totalVideoCardsPrice = videoCards * videoCardsPrice;
	double totalTransformersPrice = trasformers * trasnformersPrice;
	neededMoney = totalVideoCardsPrice + totalTransformersPrice + otherComponentsPrice;
	double moneyPerCard = videoCardProfitPerDay - videoCardsPowerConsumption;
	double profitPerDay = moneyPerCard * videoCards;
	neededTime = ceil(neededMoney / profitPerDay);


	

	cout << neededMoney << endl;
	cout << neededTime << endl;

}

int main()
{
	goldMine();
}
