#include <iostream>  
#include <climits>  
#include <string>  
#include <sstream>
#include <cctype>

using namespace std;  

void reverseString() {
	string str;
	stringstream wholeLine(str);
	while (str != "end") {
		cin >> str;
		wholeLine << str + " ";

	}

	string reversedStr = "";

	string word;
	while (wholeLine >> word && word != "end") {
		for (int i = word.length() - 1; i >= 0; i--) {
			reversedStr += word[i];
		}

		cout << word << " = " << reversedStr << endl;

		reversedStr = "";
	}
}

void repeatString() {
	string str;
	stringstream wholeLine(str);
	
	getline(cin, str);
	wholeLine << str;

	
	string word;
	while (wholeLine >> word)
	{
		for (int i = 0; i < word.length(); i++)
		{
			cout << word;
		}

	}
	
}

void substring() {
	string str;
	cin >> str;

	string wholeStr;
	cin >> wholeStr;
	
    while (wholeStr.find(str) != string::npos)
	{
		wholeStr.erase(wholeStr.find(str), str.length());
	}

	cout << wholeStr << endl;

}

void categorizedString() {
	string str;
	cin >> str;

	string letters = "", numbers = "", other = "";

	for (int i = 0; i < str.length(); i++) {
		if (isalnum(str[i])) {
			if (isalpha(str[i])) {
				letters += str[i];
			}
			else if (isdigit(str[i])) {
				numbers += str[i];
			}
		}
		else {
			other += str[i];
		}
	}

	cout << numbers << endl;
	cout << letters << endl;
	cout << other << endl;

}

int main()  
{  
	categorizedString();

	return 0;
}

/*
	string str;
	stringstream wholeLine(str);
	while (str != "end") {
		cin >> str;
		wholeLine << str + " ";

	}
	*/
