//Multidimensional Arrays - Lab
#include <iostream>
#include <cmath>

using namespace std;

void sumMatrixColumns() {
	int rows, cols;
	cin >> rows >> cols;
	int matrix[20][20] = { 0 };

	for (int row = 0; row < rows; row++) {
		for(int col = 0; col < cols; col++) {
			cin >> matrix[row][col];
		}
	}

	int sumPerColumn = 0;
	for (int col = 0; col < cols; col++) {
		for(int row = 0; row < rows; row++) {
			sumPerColumn += matrix[row][col];
		}
		cout << sumPerColumn << endl;
		sumPerColumn = 0;
	}

}

void primaryDiagonalSum() {
	int rows;
	cin >> rows;
	int m[20][20] = { 0 };
	for (int row = 0; row < rows; row++) {
		for(int col = 0; col < rows; col++) {
			cin >> m[row][col];
		}
	}
	cout << m[0][0] + m[1][1] + m[2][2] + m[3][3] << endl;
}

void symbolInMatrix() {
	int rows;
	cin >> rows;
	char m[20][20] = { 0 };
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < rows; col++) {
			cin >> m[row][col];
		}
	}
	char symbol;
	cin >> symbol;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < rows; col++) {
			if (m[row][col] == symbol) {
				cout << "(" << row << ", " << col << ")" << endl;
				return;
			}
		}
	}

	cout << symbol << " does not occur in the matrix" << endl;
}

void diagonalDiffrence() {
	int rows, leftDiagonal = 0, rightDiagonal = 0;
	cin >> rows;
	int m[20][20] = { 0 };
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < rows; col++) {
			cin >> m[row][col];
		}
	}
	for(int row = 0; row < rows; row++) {
		rightDiagonal += m[row][row];
		leftDiagonal += m[row][rows - 1 - row];
	}
	

	cout << abs(rightDiagonal - leftDiagonal) << endl;
}

int main()
{
	diagonalDiffrence();
	return 0;
}

