#include <iostream>
#include <climits>

using namespace std;


void zigZagArrays() {
	int n;
	cin >> n;
	int firstArray[100];
	int secondArray[100];
	for (int i = 0; i < n; i++)
	{
		int n1,n2;

		cin >> n1 >> n2;
		if (i % 2 == 0)
		{
			firstArray[i] = n1;
			secondArray[i] = n2;
		}
		else
		{
			firstArray[i] = n2;
			secondArray[i] = n1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << firstArray[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << secondArray[i] << " ";
	}


}


void longestSequence() {
	int n;
	cin >> n;

	int numbers[100];

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int curentNumber = numbers[0];
	int longestSequence = 1;

	int currentSequence = 1;
	int longestSequenceNumber = numbers[0];
	for (int i = 1; i < n; i++)
	{
		if (numbers[i] == curentNumber)
		{
			currentSequence++;
		}
		else
		{
			if (currentSequence >= longestSequence)
			{
				longestSequence = currentSequence;
				longestSequenceNumber = curentNumber;
			}
			curentNumber = numbers[i];
			currentSequence = 1;
		}
		if (currentSequence >= longestSequence)
		{
			longestSequence = currentSequence;
			longestSequenceNumber = curentNumber;
		}
		
		

		if (currentSequence > longestSequence)
		{
			longestSequence = currentSequence;
		}
	}

	for (int i = 0; i < longestSequence; i++)
	{
		cout << longestSequenceNumber << " ";
	}


}


void aboveAverage() {
	int n;
	cin >> n;

	int numbers[100];

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	int average = 0;

	for (int i = 0; i < n; i++)
	{
		average += numbers[i];
	}
	average /= n;

	for (int i = 0; i < n; i++)
	{
		if (numbers[i] >= average)
		{
			cout << numbers[i] << " ";
		}
	}
}

void mostFrequentNumber() {
	int n;
	cin >> n;

	int numbers[100];
	int repetions[10] = {};
	int maxRepetion = 0;

	string result = "";


	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++)
	{
		repetions[numbers[i]]++;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (repetions[i] > maxRepetion) {
			maxRepetion = repetions[i];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (repetions[i] == maxRepetion) {
			cout << i << " ";
		}
	}

	cout << endl;

}

void cartesionProduct() {
	int n;
	cin >> n;
	int array[100];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i] * array[j] << " ";
		}
	}
}

void closesNumber() {
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << "0";
		return;
	}
	int diffrence = INT_MAX;
	int array[100];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (i != j)
			{
				int currentDiffrence = abs(array[i] - array[j]);
				if (currentDiffrence < diffrence)
				{
					diffrence = currentDiffrence;
				}
			}
		}
	}

	cout << diffrence;
}

void arrayRotation() {
	int n;
	cin >> n;
	int array[100];

	for (int i = 0; i < n;i++)
	{
		cin >> array[i];
	}

	int rotaions;
	cin >> rotaions;// n = 0 => n - 1


	if (rotaions > n)
	{
		rotaions -= n;
	}

	for (int i = rotaions; i < n; i++)
	{
		cout << array[i] << " ";
	}

	for (int i = 0; i < rotaions; i++)
	{
		cout << array[i] << " ";
	}

}

void topInteger() {
	int n;
	cin >> n;
	int array[100];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < n; i++)
	{
		bool isTopInteger = true;
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] <= array[j])
			{
				isTopInteger = false;
			}
		}
		if (isTopInteger)
		{
			cout << array[i] << " ";
		}
	}

	cout << endl;
}

void magicSum() {
	int n;
	cin >> n;
	int array[100];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	int magicSum;
	cin >> magicSum;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (array[i] + array[j] == magicSum)
			{
				cout << array[i] << " " << array[j] << endl;
			}
		}
	}
}

int main()
{
	magicSum();
}

