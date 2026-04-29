#include <iostream>
#include <array>
#include <sstream>
#include <vector>

using namespace std;


void readArray(istream & inputstream, array <array<int, 10>, 10 > & m,int &rows ,int &cols) {
	inputstream >> rows;
	inputstream.ignore();
	for(int curRow = 0; curRow < rows; curRow++) {
		string row;
		getline(inputstream, row);
		istringstream mainLine(row);
		for(int curCol = 0; curCol < cols; curCol++) {
			mainLine >> m[curRow][curCol];
		}
		istringstream istr(row);
		cols = 0;
		while(istr >> m[curRow][cols]) {
			cols++;
		}
	}
}
void compareMatrices() {
	array <array<int, 10>, 10 > matrix1, matrix2;
	int rows1, cols1, rows2, cols2;

	readArray(cin, matrix1, rows1, cols1);
	readArray(cin, matrix2, rows2, cols2);

	for(int curRow = 0; curRow < rows1; curRow++) {
		for(int curCol = 0; curCol < cols1; curCol++) {
			if(matrix1[curRow][curCol] != matrix2[curRow][curCol]) {
				cout << "not equal" << endl;
				return;
			}
		}
	}
	cout << "equal" << endl;

}

void positionOf() {
	int rows, cols;
	array <array<int, 10>, 10 > matrix;
	cin >> rows >> cols;

	for(int curRow = 0; curRow < rows; curRow++) {
		for(int curCol = 0; curCol < cols; curCol++) {
			cin >> matrix[curRow][curCol];
		}
	}

	int numberSearchingFor;
	cin >> numberSearchingFor;

	bool found = false;
	for(int curRow = 0; curRow < rows; curRow++) {
		for(int curCol = 0; curCol < cols; curCol++) {
			if(matrix[curRow][curCol] == numberSearchingFor) {
				cout << curRow << " " << curCol << endl;
				found = true;
			}
		}
	}

	if (!found) {
		cout << "not found" << endl;
	}
}

bool is2x2(const array <array<char, 10>, 10 > & m,int &rows, int &cols) {
	char currentChar = m[rows][cols];
	return  currentChar == m[rows+1][cols]&&
			currentChar == m[rows][cols+1]&&
			currentChar == m[rows+1][cols+1];
}
void squaresInMatrix() {
	int rows, cols, squareCount = 0;
	array <array<char, 10>, 10 > matrix;
	cin >> rows >> cols;

	for(int curRow = 0; curRow < rows; curRow++) {
		for(int curCol = 0; curCol < cols; curCol++) {
			cin >> matrix[curRow][curCol];
		}
	}

	for(int curRow = 0; curRow < rows - 1; curRow++) {
		for(int curCol = 0; curCol < cols - 1; curCol++) {
			if (is2x2(matrix, curRow, curCol)) {
				squareCount++;
			}
		}
	}
	cout << squareCount << endl;

}

void snakeMove() {
	int collums, rows;
	string snake;
	cin >> collums >> rows >> snake;
	char park[12][12] = { 0 };

	const int snakeEnd = snake.length();
	int snakeIndex = 0;
	for (int i = 0; i < collums; i++) 
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < rows; j++)
			{
				park[i][j] = snake[snakeIndex];
				snakeIndex++;
				if (snakeIndex == snakeEnd)
					snakeIndex = 0;
			}
		}
		else
		{
			for (int j = collums; j >= 0; --j)
			{
				park[i][j] = snake[snakeIndex];
				snakeIndex++;
				if (snakeIndex == snakeEnd)
					snakeIndex = 0;
			}
		}
		
	}

	for (int i = 0; i < collums; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << park[i][j];
		}
		cout << endl;
	}
}

int is3x3(int m[50][50], int& rows, int& cols,int (&sumPossitionsArr)[50][50]) {
	int sumInFunc = 0;
	int newArrayCols = 0;
	int newArrayRows = 0;

	for(int row = rows; row < rows + 3; row++,newArrayRows++) {
		for(int col = cols; col < cols + 3; col++,newArrayCols++) {
			sumPossitionsArr[newArrayRows][newArrayCols] = m[row][col];
			sumInFunc += m[row][col];
		}
		newArrayCols = 0;
	}
	return sumInFunc;
}
void maxSumIn3x3() {
	int arr[50][50] = { 0 };
	int rows, cols, sum = 0, array[50][50] = { 0 };
	cin >> rows >> cols;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> arr[row][col];
		}
	}

	for (int row = 0; row < rows-1; row++) {
		for (int col = 0; col < cols-1; col++) {
			int currArr[50][50] = { 0 };
			int currSum = is3x3(arr, row, col, currArr);
			
			if (sum < currSum) {
				sum = currSum;
				for (int row = 0; row < rows; row++) {
					for (int col = 0; col < cols; col++) {
						array[row][col] = currArr[row][col];
					}
				}
			}
				
		}
	}
	cout << "Sum = " << sum << endl;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cout << array[row][col] << " ";
		}
		cout << endl;
	}
}


void printRightDiagonal(const vector<vector<int>> &v, int sRow, int sCol) {
	int lastCol = v[0].size() - 1;

	for(int row = sRow, col = sCol; row >= 0 && col <= lastCol; row--, col++) {
		cout << v[row][col] << ' ';
	}
	cout << endl;
}
void reverseMatrixDiaonal() {
	vector<vector<int>> arr;
	int rows, cols;
	cin >> rows >> cols;

	arr.resize(rows, vector<int>(cols));

	for (size_t row = 0; row < rows; row++) {
		for(size_t col = 0; col < cols; col++) {
			cin >> arr[row][col];
		}
	}

	for(int col = arr[0].size()-1; col >= 0; col--) {
		printRightDiagonal(arr, arr.size()-1, col);
	}

	for (int row = arr.size()-2; row >= 0; row--) {
			printRightDiagonal(arr, row, 0);
		
	}

	
}

void printMethodA(vector<vector<int>> &m, int cols, int rows) {
	int number = 1;
	for(int col = 0; col < cols; col++) {
		for(int row = 0; row < rows; row++) {
			m[row][col] = number;
			number++;
		}
	}
}
void printMethodB(vector<vector<int>>& m, int cols, int rows) {
	int numberForEven = 1;
	int numberForOdd = 1;
	int numberPossitionRow;
	int numberPossitionCol;
	bool passed = false;
	if (rows >= 4) {
		numberPossitionRow = rows - 1;
		numberPossitionCol = cols - m.size();
	}
	else {
		numberPossitionRow = rows - 1;
		numberPossitionCol = cols - 2;
	}
	
	for (int col = 0; col < cols; col++) {
		for (int row = 0; row < rows; row++) {
			if(col % 2 == 1) {
				if (col == 3 && !passed) {
					numberPossitionCol = cols - m.size()-3;
					numberPossitionRow = rows - m.size()-1;
					passed = true;
				}
				numberForOdd = numberForEven;
				m[numberPossitionRow][numberPossitionCol] = numberForOdd;
				numberPossitionRow--;
			}
			else {
				m[row][col] = numberForEven;
			}
			numberForEven++;
		}
	}
}
void fillMatrix() {
	int cols;
	cin >> cols;
	int rows = cols;

	cin.ignore();

	char method;
	cin >> method;

	vector<vector<int>> matrix;
	matrix.resize(rows, vector<int>(cols));

	if (method == 'A') {
		printMethodA(matrix, cols, rows);
	}
	else{
		printMethodB(matrix, cols, rows);
	}

	for(int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			cout << matrix[row][col] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	reverseMatrixDiaonal();
}