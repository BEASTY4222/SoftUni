#include <iostream>
#include <string>

using namespace std;

void examPreperation() {
	int maxBadGradesCount;
	cin >> maxBadGradesCount;

	int currentBadGradesCount = 0, sum = 0, count = 0;
	bool isSuccessful = true;

	string input, lastProblem;
	while (getline(cin >> ws, input) && input != "Enough") {
		int grade;
		cin >> grade;

		sum += grade;
		count++;
		lastProblem = input;

		if (grade <= 4) {
			currentBadGradesCount++;
			if (currentBadGradesCount == maxBadGradesCount) {
				isSuccessful = false;
				break;
			}
		}

		// NOTE: The previous if statement is equivalent to:
		// if (grade <= 4 && ++currentBadGradesCount == maxBadGradesCount) {
		// 	  isSuccessful = false;
		//	  break;
		// }
	}

	if (isSuccessful) {
		cout.setf(ios::fixed);
		cout.precision(2);

		cout << "Average score: " << 1.0 * sum / count << endl;
		cout << "Number of problems: " << count << endl;
		cout << "Last problem: " << lastProblem << endl;
	}
	else {
		cout << "You need a break, " << currentBadGradesCount << " poor grades." << endl;
	}
}

void oldBooks() {
	string bookToLookFor;
	getline(cin, bookToLookFor);

	int booksCount = 0;
	bool isFound = false;

	string input;
	while (getline(cin, input) && input != "No More Books") {
		if (input == bookToLookFor) {
			isFound = true;
			break;
		}

		booksCount++;
	}

	if (isFound) cout << "You checked " << booksCount << " books and found it." << endl;
	else cout << "The book you search is not here!" << endl << "You checked " << booksCount << " books." << endl;
}

void steps() {
	const int goalLimit = 10000;

	int totalSteps = 0;
	bool shouldContinue = true, goalIsReached = false;

	while (shouldContinue && !goalIsReached) {
		string input;
		getline(cin, input);

		int currentSteps;
		if (input == "Going home") {
			cin >> currentSteps;
			shouldContinue = false;
		}
		else currentSteps = stoi(input);

		totalSteps += currentSteps;
		if (totalSteps >= goalLimit) goalIsReached = true;
	}

	if (goalIsReached) cout << "Goal reached! Good job!" << endl;
	else cout << goalLimit - totalSteps << " more steps to reach goal." << endl;
}

void coins() {
	double change;
	cin >> change;

	int coins = change * 100;
	int coinsCount = 0;

	while (coins > 0)
	{
		if (coins >= 200)
		{
			
			coins -= 200;
		}
		else if (coins >= 100)
		{
			coins -= 100;
			

		}
		else if (coins >= 50)
		{
			coins -= 50;
			

		}
		else if (coins >= 20)
		{
			coins -= 20;
			

		}
		else if (coins >= 10)
		{
			coins -= 10;
			

		}
		else if (coins >= 5)
		{
			coins -= 5;


		}
		else if (coins >= 2)
		{
			coins -= 2;
	
		}
		else 
		{
			coins -= 1;
		

		}
		coinsCount++;
	}
	
	cout << coinsCount << endl;

}

void cake() {
	int width, length;
	cin >> width >> length;
	int cakeSize = width * length;
	bool cakeLeft = true;

	int pieces = 0;
	string command;
	while (cakeSize > 0 && cin >> command && command != "STOP")
	{

		int piece = stoi(command);
		pieces += piece;
		if (pieces > cakeSize)
		{
			cout << "No more cake left! You need " << abs(pieces - cakeSize) << " pieces more." << endl;
			cakeLeft = false;
			break;
		}

	}
	if (cakeLeft)
	{
		cout << cakeSize - pieces << " pieces are left." << endl;
	}
}

void moving() {
	int width, length, height;
	cin >> width >> length >> height;

	int freeSpace = width * length * height;
	int boxes = 0;
	bool noSpace = false;

	string command;
	while (freeSpace > 0 && cin >> command && command != "Done")
	{
		int box = stoi(command);
		boxes += box;
		if (boxes > freeSpace)
		{
			cout << "No more free space! You need " << abs(boxes - freeSpace) << " Cubic meters more." << endl;
			noSpace = true;
			break;
		}
	}
	if (!noSpace)
	{
		cout << freeSpace - boxes << " Cubic meters left." << endl;
	}
}


int main()
{
	steps();
}
