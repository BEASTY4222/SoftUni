#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <iomanip>

using namespace std;

void swimingChampionship() {
	int days, neededPoints, numberOfSwimmers;
	double hotelFeePerSwimmer, participationFeePerSwimmer;
	vector<double> points;

	cin >> days >> neededPoints >> numberOfSwimmers >> hotelFeePerSwimmer >> participationFeePerSwimmer;
	points.reserve(days);

	for (int i = 0; i < days; i++)
	{
		double temp;
		cin >> temp;
		points.push_back(temp);
	}

	double moneySpentForHotel = (hotelFeePerSwimmer * numberOfSwimmers) * days;
	double moneySpent = moneySpentForHotel + (participationFeePerSwimmer * numberOfSwimmers);
	double totalPoints = 0.0;
	for (int i = 0; i < days; i++)
	{
		totalPoints += points[i];
		if (i > 0) {
			totalPoints += points[i] * 0.05;
		}
	}

	double discount = 0.0;
	if (totalPoints >= neededPoints)
	{
		discount = moneySpent * 0.25;
		moneySpent -= discount;
		cout << fixed << setprecision(2) << "Money left to pay: " << moneySpent <<  " BGN." << endl;
		cout << "The championship was successful!" << endl;
	}
	else
	{
		discount = moneySpent * 0.10;
		moneySpent -= discount;
		cout << fixed << setprecision(2) << "Money left to pay: " << moneySpent << " BGN." << endl;
		cout << "The championship was not successful." << endl;
	}
	

}

void arrayToNumber() {
	int n;
	cin >> n;
	vector<int> numbers;
	numbers.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	if (n == 1) {
		cout << numbers[0];
		return;
	}

	int end = 1;
	while (numbers.size() > 1) {
		vector<int> temp;
		for (int i = 0; i < numbers.size()-1; i++)
		{
			temp.push_back(numbers[i] + numbers[i + 1]);
		}
		numbers = temp;
	}
	
	cout << numbers[0];

}

void train() {
	string contensOfAWagon;
	string wagon;
	vector<string> trainWagons;

	while (true) {
		getline(cin, contensOfAWagon);
		if (contensOfAWagon == "end")
		{
			break;
		}
		else if (contensOfAWagon == "empty") {
			trainWagons.push_back(" ");
		}
		else
			trainWagons.push_back(contensOfAWagon);
	}



	char command;
	while (true) {
		cin >> command;
		if (command == 'E') {
			break;
		}
		else if (command == 'P') {
			for (int i = 0; i < trainWagons.size(); i++)
			{
				if (i == trainWagons.size() - 1) {
					cout << "|" << trainWagons[i] << "|";
				}
				else
					cout << "|" << trainWagons[i];
			}
			cout << endl;
		}
		else if (command == 'M') {
			int oldWagonIndex, newWagonIndex;
			cin >> oldWagonIndex >> newWagonIndex;
			if (oldWagonIndex == trainWagons.size()) {
				string tempWagon = trainWagons[oldWagonIndex - 1];
				trainWagons.insert(trainWagons.begin(), tempWagon);
				trainWagons.pop_back();
			}
			else if (oldWagonIndex - newWagonIndex > 1) {
				string tempWagon = trainWagons[newWagonIndex - 1];
				string wagonBetween = trainWagons[oldWagonIndex];
				trainWagons[newWagonIndex - 1] = trainWagons[oldWagonIndex - 1];
				trainWagons[oldWagonIndex - 2] = tempWagon;
				trainWagons[oldWagonIndex - 1] = wagonBetween;

			}
			else if (newWagonIndex - oldWagonIndex > 1) {
				string tempWagon = trainWagons[newWagonIndex - 1];
				trainWagons[newWagonIndex - 1] = trainWagons[oldWagonIndex - 1];
				trainWagons[oldWagonIndex - 1] = tempWagon;
			}

			else
			{
				string tempWagon = trainWagons[newWagonIndex - 1];
				trainWagons[newWagonIndex - 1] = trainWagons[oldWagonIndex - 1];
				trainWagons[oldWagonIndex - 1] = tempWagon;
			}
			for (int i = 0; i < trainWagons.size(); i++)
			{
				if (i == trainWagons.size() - 1) {
					cout << "|" << trainWagons[i] << "|";
				}
				else
					cout << "|" << trainWagons[i];
			}
			cout << endl;
		}
		else
		{
			int wagonIndex;
			cin >> wagonIndex;
			wagonIndex--;
			trainWagons.erase(trainWagons.begin() + wagonIndex);
			for (int i = 0; i < trainWagons.size(); i++)
			{
				if (i == trainWagons.size() - 1) {
					cout << "|" << trainWagons[i] << "|";
				}
				else
					cout << "|" << trainWagons[i];
			}
			cout << endl;
		}
	}
}

int main()
{
	train();
}