#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;



void mergeTrains() {
	string trainA, trainB;
	getline(cin, trainA);
	getline(cin, trainB);
	
	stringstream ssA(trainA);
	stringstream ssB(trainB);

	list<int> trainListA, trainListB, finalTrain;
	string finalTrainStr;

	int n;

	while (ssA >> n) {
		trainListA.push_back(n);
	}
	while (ssB >> n) {
		trainListB.push_back(n);
	}

	int railcart = 0;
	while(trainListA.size() || trainListB.size()) {
		if (trainListA.empty()) {
			finalTrain.push_front(trainListB.back());
			trainListB.pop_back();
			finalTrainStr += 'B';
			continue;
		}
		else if(trainListB.empty()){
			finalTrain.push_front(trainListA.back());
			trainListA.pop_back();
			finalTrainStr += 'A';
			continue;
		}

		if (trainListA.back() < trainListB.back())
		{
			finalTrain.push_front(trainListA.back());
			trainListA.pop_back();
			finalTrainStr += 'A';
		}
		else
		{
			finalTrain.push_front(trainListB.back());
			trainListB.pop_back();
			finalTrainStr += 'B';
		}
	}

	cout << finalTrainStr << endl;
	for (list<int>::iterator it = finalTrain.begin(); it != finalTrain.end(); ++it)
	{
		cout << *it << " ";
	}
}

bool checkBrackets(string line) {

	int roundBrackets = 0;
	int squareBrackets = 0;
	int curlyBrackets = 0;


	for (char c : line)
	{
		switch (c) {
		case '(':
			roundBrackets++;
			break;
		case ')':
			if (roundBrackets <= 0) return false;
			roundBrackets--;
			break;
		case '[':
			squareBrackets++;
			if (roundBrackets != 0) return false;
			break;
		case ']':
			if (squareBrackets <= 0 || roundBrackets > 0) return false;
			squareBrackets--;
			break;
		case '{':
			curlyBrackets++;
			if (roundBrackets != 0 || squareBrackets > 0) return false;
			break;
		case '}':
			if (roundBrackets != 0 || squareBrackets > 0) return false;
			if (curlyBrackets <= 0) return false;
			curlyBrackets--;
			break;
		}
		
	}

	return roundBrackets == 0 && squareBrackets == 0 && curlyBrackets == 0;
}
void braceket() {
	string wholeLineBrackets;
	getline(cin, wholeLineBrackets);

	if (checkBrackets(wholeLineBrackets)) {
		cout << "valid";
	}
	else {
		cout << "invalid";
	}
}

void pipes() {
	int n;
	cin >> n;

	vector<int> lifetime;
	vector<int> installation;
	installation.reserve(n);
	vector<int> checkups;
	checkups.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int checkup;
		cin >> checkup;
		checkups.push_back(checkup);
	}
	for (int i = 0; i < n; i++)
	{
		int pipe;
		cin >> pipe;
		installation.push_back(pipe);
	}

	for (int i = 0; i < n; i++)
	{
		int damage = installation[i] - checkups[i];
		int yearsTillReplacement = installation[i] / damage;
		lifetime.push_back(yearsTillReplacement);
	}


	for (int i = 0; i < n; i++)
	{
		cout << lifetime[i] << " ";
	}


}

int convertToMinutes(const string& militaryTime) {
	int hours = stoi(militaryTime.substr(0, 1));
	hours *= 10;
	hours += stoi(militaryTime.substr(1, 1));

	int minutes = stoi(militaryTime.substr(2, 2));
	return hours * 60 + minutes;
}
void bus() {
	int n;
	cin >> n;

	string militaryTimeStr;
	vector<string> militaryTimeV;
	for (int i = 0; i < n; i++)
	{
		string time;
		cin >> time;
		militaryTimeV.push_back(time);
	}

	string boatMilitaryDepartureTime;
	cin >> boatMilitaryDepartureTime;
	int boatDepartureTime = convertToMinutes(boatMilitaryDepartureTime);

	vector <int> busDepartureTimes;
	for (int i = 0; i < n; i++)
	{
		int busDepartureMinutes = convertToMinutes(militaryTimeV[i]);
		busDepartureTimes.push_back(busDepartureMinutes);
	}

	int bestDifference = INT_MAX;
	int bestBusIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int timeDifference = abs(boatDepartureTime - busDepartureTimes[i]);

		if (timeDifference <= bestDifference) {
			bestBusIndex = i;
			bestDifference = timeDifference;
		}
	}

	cout << bestBusIndex + 1 << endl;


}

int main()
{
	bus();

	return 0;
}

