#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void gausTrick() {
	vector<int> numbers;

	string line;
	getline(cin, line);
	istringstream iss(line);

	while (iss >> line) {
		numbers.push_back(stoi(line));
	}

	vector<int> sums;
	size_t sizeOfSums = (numbers.size() / 2) + (numbers.size() % 2);

	for (int i = 0; i < sizeOfSums; i++) {
		if(i == sizeOfSums-1 && sizeOfSums % 2 == 1) {
			sums.push_back(numbers[i]);
		}
		else{
			sums.push_back(numbers[i] + numbers[numbers.size() - 1 - i]);
		}
	}
	
	for (int i = 0; i < sizeOfSums; i++) {
		cout << sums[i] << ' ';
	}
	
}

void removeNegativesAndReverse() {
	vector<int> numbers;

	string line;
	getline(cin, line);
	istringstream iss(line);

	while (iss >> line)
	{
		numbers.push_back(stoi(line));
	}

	for(int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] < 0)
		{
			numbers.erase(numbers.begin() + i);
			i--;
		}
	}

	if(numbers.empty())
	{
		cout << "empty" << endl;
		return;
	}

	for(int i = numbers.size() - 1; i >= 0; i--)
	{
		cout << numbers[i] << ' ';
	}
}

void printInParts() {
	int numbers[20][20] = { 0 };

	int rows, cols;
	cin >> rows >> cols;

	for (int row = 0; row < rows; row++)
		for (int col = 0; col < cols; col++)
			cin >> numbers[row][col];


	int newRows, newCols;
	cin >> newRows >> newCols;

	for (int row = 0; row < newRows; row++) {
		for (int col = 0; col < newCols; col++)
			cout << numbers[row][col]<< ' ';
		cout << endl;
	}
}

string makeLowerCase(string str) {
	for (int i = 0; i < str.length();i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}
string makeUpperCase(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}
void someOrdering() {
	string line;
	getline(cin, line);

	cout << makeLowerCase(line) << endl;
	cout << makeUpperCase(line) << endl;
}

int countTokens(string line) {
	int count = 0;
	istringstream iss(line);
	string word;
	while (iss >> word) {
		count++;
	}
	return count;
}
void readMatrix(int(&m)[10][10], int& rows, int& cols, istringstream& line) {
    string lineStr = line.str();
    cols = countTokens(lineStr);
    vector<int> numbersForMatrix;

    int num;
    while (line >> num) {
        numbersForMatrix.push_back(num);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            m[row][col] = numbersForMatrix[col];
        }
    }
}
void compareM() {
    int m1r, m1c, m2r, m2c;
    int m1[10][10] = { 0 };
    int m2[10][10] = { 0 };

    string lineM1, lineM2;

	getline(cin, lineM1);
	m1r = stoi(lineM1);
    getline(cin, lineM1);
    istringstream isM1(lineM1);

	getline(cin, lineM2);
	m2r = stoi(lineM2);
    getline(cin, lineM2);
    istringstream isM2(lineM2);

    readMatrix(m1, m1r, m1c, isM1);
    readMatrix(m2, m2r, m2c, isM2);

	for (int row = 0; row < m1r; row++) {
		for (int col = 0; col < m1c; col++) {
			if(m1[row][col] != m2[row][col]) {
				cout << "not equal" << endl;
				return;
			}
		}
	}

	cout << "equal" << endl;
}

void applyMines(char(&mineField)[50][50], int(&finalMineField)[50][50], int row, int col) {
	if (row < 0 || row >= 20 || col < 0 || col >= 20)
		return;

	finalMineField[row][col]++;

	int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int d = 0; d < 8; d++) {
		int nr = row + dr[d];
		int nc = col + dc[d];

		if (nr >= 0 && nr < 20 && nc >= 0 && nc < 20) {
			finalMineField[nr][nc]++;
		}
	}
}
void mineSweaper() {
	char StartMineField[50][50] = { 0 };
	int finalMineField[50][50] = { 0 };

	int rows, cols;
	cin >> rows >> cols;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> StartMineField[row][col];
		}
	}

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (StartMineField[row][col] == '!') {
				applyMines(StartMineField, finalMineField, row, col);
			}
		}
	}

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << finalMineField[row][col];
		}
		cout << endl;
	}

}

int main()
{
	mineSweaper();
}

