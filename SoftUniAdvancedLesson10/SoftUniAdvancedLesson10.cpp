#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <string>

using namespace std;

string toUpperCase(const string &str) {
	string result;
	for (char c : str) {
		result += toupper(c);
	}
	return result;
}
string toLowerCase(const string &str) {
	string result;
	for (char c : str) {
		result += tolower(c);
	}
	return result;
}
void extractWords(string text,char seacrhedChar) {
	string word;
	set<string> words;
	istringstream iss(text);
	while (iss >> word) {
		string upperWord = toUpperCase(word);
		string lowerWord = toLowerCase(word);
		for (int i = 0; i < word.length(); i++) {
			if (lowerWord[i] == seacrhedChar || upperWord[i] == seacrhedChar) {
				words.insert(word);

			}
		}
	}
	for (auto it = words.begin(); it != words.end(); ) {
		cout << *it << ' ';
		it = words.erase(it);
	}
	cout << endl;
}
void letters() {
	string text, word;
	getline(cin, text);

	for(char &c : text) {
		if(!isalpha(c)) {
			c = ' ';
		}
	}

	char searchChar;
	while(cin >> searchChar && searchChar != '.') {
		extractWords(text,searchChar);
	}
}

void copyM(char(&source)[10][10], char(&dest)[10][10]) {
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++)
		{
			dest[row][col] = source[row][col];
		}
	}
}
void applyRust(char (&matrix)[10][10], char(&finalMatrix)[10][10]) {


	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++)
		{
			if (matrix[row][col] == '!') {
				if (row > 0 && finalMatrix[row - 1][col] != '#') {
					finalMatrix[row - 1][col] = '!';
				}
				if (row < 9 && finalMatrix[row + 1][col] != '#') {
					finalMatrix[row + 1][col] = '!';
				}
				if (col < 9 && finalMatrix[row][col + 1] != '#') {
					finalMatrix[row][col + 1] = '!';
				}
				if (col > 0 && finalMatrix[row][col - 1] != '#') {
					finalMatrix[row][col - 1] = '!';
				}
			}
		}
	}
	
	
	
}
void rust() {
	char matrix[10][10] = { 0 };
	char finalMatrix[10][10] = { 0 };

	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++)
		{
			cin >> matrix[row][col];
		}
	}

	copyM(matrix,finalMatrix);

	int turns;
	cin >> turns;

	while (turns--)
	{
		applyRust(matrix, finalMatrix);
		copyM(finalMatrix, matrix);
	}
	
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++)
		{
			cout << matrix[row][col];
		}
		cout << endl;
	}

}

void matchingLocations() {
	vector<string>names;
	vector<string>laptitideLongtitude;
	string input;

	//input
	while (true) {
		getline(cin, input);
		istringstream iss(input);

		string buf;
		getline(iss, buf, ',');
		if (buf == ".") {
			break;
		}
		if(isalpha(buf[0]))
			names.push_back(buf);
	
		getline(iss, buf);
		if (isdigit(buf[0]))
			laptitideLongtitude.push_back(buf);
	}

	//output
	while (true) {
		string searchedFor;
		getline(cin, searchedFor);

		if (searchedFor == ".")
			break;
		if (isalpha(searchedFor[0])) {
			for (int i = 0; i < names.size(); i++) {
				if (names[i] == searchedFor) {
					cout << names[i] << "," << laptitideLongtitude[i] << endl;
				}
			}
		}
		else if (isdigit(searchedFor[0])) {
			istringstream issForDigit(searchedFor);

			string firstPart;
			string secondPart;
			issForDigit >> firstPart;
			issForDigit >> secondPart;

			firstPart += ",";
			string finalresult = firstPart + secondPart;

			for (int i = 0; i < laptitideLongtitude.size(); i++) {
				if (laptitideLongtitude[i] == finalresult) {
					cout << names[i] << "," << laptitideLongtitude[i] << endl;
				}
			}
		}



	}
	

	
}

int main()
{
	letters();
}
