#include <iostream>
#include <iomanip>

using namespace std;


void tradeCommision() {
	string city;
	double sales, commissionPercent;

	cin >> city >> sales;

	if (sales < 0) {
		cout << "error";
		return;
	}

	if (city == "Sofia") {
		if (sales <= 500) {
			commissionPercent = 0.05;
		}
		else if (sales <= 1000) {
			commissionPercent = 0.07;
		}
		else if (sales <= 10000) {
			commissionPercent = 0.08;
		}
		else {
			commissionPercent = 0.12;
		}
	}
	else if (city == "Varna") {
		if (sales <= 500) {
			commissionPercent = 0.045;
		}
		else if (sales <= 1000) {
			commissionPercent = 0.075;
		}
		else if (sales <= 10000) {
			commissionPercent = 0.10;
		}
		else {
			commissionPercent = 0.13;
		}
	}
	else if (city == "Plovdiv") {
		if (sales <= 500) {
			commissionPercent = 0.055;
		}
		else if (sales <= 1000) {
			commissionPercent = 0.08;
		}
		else if (sales <= 10000) {
			commissionPercent = 0.12;
		}
		else {
			commissionPercent = 0.145;
		}
	}
	else {
		cout << "error";
		return;
	}

	cout << fixed << setprecision(2) << commissionPercent * sales;

}

void fruitShop() {
	string product, dayOfTheWeek;
	double quantity, price = 0;

	cin >> product >> dayOfTheWeek >> quantity;

	bool isWeekend = (dayOfTheWeek == "Saturday" || dayOfTheWeek == "Sunday");
	bool isWorkday = (
		dayOfTheWeek == "Monday" || dayOfTheWeek == "Tuesday" ||
		dayOfTheWeek == "Wednesday" || dayOfTheWeek == "Thursday" ||
		dayOfTheWeek == "Friday"
		);

	if (product == "banana") {
		price = isWeekend ? 2.70 : 2.50;
	}
	else if (product == "apple") {
		price = isWeekend ? 1.25 : 1.20;
	}
	else if (product == "orange") {
		price = isWeekend ? 0.90 : 0.85;
	}
	else if (product == "grapefruit") {
		price = isWeekend ? 1.60 : 1.45;
	}
	else if (product == "kiwi") {
		price = isWeekend ? 3.00 : 2.70;
	}
	else if (product == "pineapple") {
		price = isWeekend ? 5.60 : 5.50;
	}
	else if (product == "grapes") {
		price = isWeekend ? 4.20 : 3.85;
	}

	if (price == 0 || (!isWeekend && !isWorkday)) {
		cout << "error";
	}
	else {
		cout << fixed << setprecision(2) << (price * quantity);
	}

}

void invalidNumber() {
	int num;
	cin >> num;

	if (!((num >= 100 && num <= 200) || num == 0))
	{
		cout << "invalid";
	}
}

void fruitOrVegetable() {
	string name;
	cin >> name;
	bool fruit = name == "banana" || name == "apple" || name == "kiwi" || name == "cherry"
		|| name == "lemon" || name == "grapes";
	bool vegetable = name == "tomato" || name == "cucumber" || name == "pepper" 
		|| name == "carrot";

	if (fruit)
	{
		cout << "fruit";
	}
	else if (vegetable) {
		cout << "vegetable";
	}
	else {
		cout << "unknown";
	}
}

void cinemaTicket() {
	string day;

	cin >> day;

	if (day == "Monday" || day == "Tuesday" || day == "Friday")
	{
		cout << 12;
	}
	else if (day == "Wednesday" || day == "Thursday") {
		cout << 14;
	}
	else if (day == "Saturday" || day == "Sunday") {
		cout << 16;
	}
}

void workingHours() {
	int timeOfDay;
	string weekDay;

	cin >> timeOfDay >> weekDay;

	bool working = timeOfDay <= 10 && timeOfDay <= 18;
	bool open = weekDay == "Monday" || weekDay == "Tuesday" || weekDay == "Wendsday" || weekDay == "Thursday" || weekDay == "Friday" || weekDay == "Saturday";

	if (working && open)
	{
		cout << "open";
	}
	else
	{
		cout << "closed";
	}
}

void numberInRange() {
	int num;
	cin >> num;

	if (num >= -100 && num <= 100 && num != 0)
	{
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

void smallShop() {
	string product, city;
	double quantity;
	double priceForOne;

	cin >> product >> city >> quantity;

	if (city == "Sofia") {
		if (product == "coffee") {
			priceForOne = 0.50;
		}
		else if (product == "water") {
			priceForOne = 0.80;
		}
		else if (product == "beer") {
			priceForOne = 1.20;
		}
		else if (product == "sweets") {
			priceForOne = 1.45;
		}
		else if (product == "peanuts") {
			priceForOne = 1.60;
		}
	}
	else if (city == "Varna") {
		if (product == "coffee") {
			priceForOne = 0.45;
		}
		else if (product == "water") {
			priceForOne = 0.70;
		}
		else if (product == "beer") {
			priceForOne = 1.10;
		}
		else if (product == "sweets") {
			priceForOne = 1.35;
		}
		else if (product == "peanuts") {
			priceForOne = 1.55;
		}
	}
	else if (city == "Plovdiv") {
		if (product == "coffee") {
			priceForOne = 0.40;
		}
		else if (product == "water") {
			priceForOne = 0.70;
		}
		else if (product == "beer") {
			priceForOne = 1.15;
		}
		else if (product == "sweets") {
			priceForOne = 1.30;
		}
		else if (product == "peanuts") {
			priceForOne = 1.50;
		}
	}

	double totalPrice = quantity * priceForOne;

	cout << totalPrice;

}

void personalTitles() {
	double age;
	char gender;
	string title;

	cin >> age >> gender;

	if (gender == 'm')
	{
		title = "Master";
		if (age >= 16) {
			title = "Mr.";
		}

	}
	else if(gender == 'f')
	{
		title = "Miss";
		if (age >= 16) {
			title = "Ms.";
		}
		
	}

	cout << title;
}

void animalType() {
	string animal;
	cin >> animal;

	if (animal == "dog") {
		cout << "mammal";
	}
	else if (animal == "crocodile" || animal == "tortoise" || animal == "snake") {
		cout << "reptile";
	}
	else
	{
		cout << "error";
	}
}

void wowkingDays() {
	string day;
	cin >> day;

	if (day == "Monday")
	{
		cout << "Working day";
	}
	else if (day == "Tuesday") {
		cout << "Working day";
	}
	else if (day == "Wednesday") {
		cout << "Working day";
	}
	else if (day == "Thursday") {
		cout << "Working day";
	}
	else if (day == "Friday") {
		cout << "Working day";
	}
	else if (day == "Saturday") {
		cout << "Weekend";
	}
	else if (day == "Sunday") {
		cout << "Weekend";
	}
	else {
		cout << "Error";
	}


}

void dayOfTheWeek() {
    int num;
    cin >> num;

	switch (num)
	{
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 7:
		cout << "Sunday";
		break;
	default:
		cout << "Error";
		break;
	}

}

int main()
{
	fruitOrVegetable();
}

