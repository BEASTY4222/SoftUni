#include <iostream>  
#include <string>  
#include <sstream>
#include <cctype>

using namespace std;  

//for validusername
bool checkUsername(string name) {
	for (int i = 0; i < name.length(); i++)
	{
		bool nameSize = !(name.length() < 3 || name.length() > 16);
		bool nameElements = (isalnum(name[i]) || (name[i] == '-' || name[i] == '_'));

		if (!(nameSize && nameElements))
		{
			return false;
		}
	}
	return true;
}
void validUsername() {  
   string username;  
   getline(cin, username);  
   stringstream wholeLine(username);

   bool isValidName = false;
   string name;
   while (getline(wholeLine, name, ','))
   {
	   if (name[0] == ' ')
	   {
		   name = name.substr(1);
	   }
	   if (checkUsername(name))
	   {
		   cout << name << endl;
		   isValidName = false;
	   }
	   
   }
}  

void ceaserCipher() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		str[i] += 3;
	}
	cout << str << endl;
}

void replaceRepeatingChars() {
	string word;
	getline(cin, word);
	ostringstream result;
	char curr = word[0];
	for (char c:word)
	{
		if (c != curr)
		{
			result << curr;
			curr = c;
		}
	}
	result << curr;
	
	string outputWord = result.str();
	cout << outputWord << endl;


}

void charMultiplicaion() {
	string str1, str2;
	cin >> str1 >> str2;

	int sum = 0, maxLenght = 0;

	if (str1.length() > str2.length())
	{
		maxLenght = str1.length();
	}
	else
	{
		maxLenght = str2.length();
	}


	for (int i = 0; i < maxLenght; i++)
	{
		if (str1.length() == str2.length())
		{
			sum += str1[i] * str2[i];
		}
		if (str1.length() > str2.length())
		{
			if (i < str2.length()) {
				sum += str1[i] * str2[i];
			}
			else {
				sum += str1[i];
			}
		}
		if (str1.length() < str2.length())
		{
			if (i >= str1.length()) {
				sum += str2[i];
			}
			else {
				sum += str1[i] * str2[i];
			}

		}
	}

	cout << sum << endl;

}

void mathExpresion() {
	string str;
	getline(cin, str);

	stringstream ss(str);

	char bracket;
	int bracketsCount = 0;

	while (ss >> bracket)
	{
		switch (bracket)
		{
		case '(':
			bracketsCount++;
			break;
		case ')':
			bracketsCount--;
			break;
		}
	}

	if (bracketsCount != 0)
		cout << "incorrect";
	else
		cout << "correct";
}

void titleCase() {
	string str;
	getline(cin, str);
	stringstream ss(str);

	bool needsUpper = 1;
	for (int i = 0; i < str.length();i++) {
		if (!isalnum(str[i]))
		{
			needsUpper++;
			continue;
		}
		if (needsUpper > 0)
		{
			str[i] = toupper(str[i]);
			needsUpper = 0;
		}
	}
	
	cout << str;

	
}

void replaceAll() {
	string str;
	getline(cin, str);
	
	string findWord;
	cin >> findWord;
	string replaceWord;
	cin >> replaceWord;

	while (str.find(findWord) != string::npos)
	{
		str.replace(str.find(findWord), findWord.length(), replaceWord);
	}

	cout << str << endl;
}

void invalidInput() {
	string str;
	getline(cin, str);
	stringstream ss(str);

	int sum = 0;
	ostringstream result;
	while (ss >> str)
	{
		istringstream convertStream(str);
		int number;
		if (convertStream >> number)
		{
			sum += number;
		}
		else
		{
			result << str << " ";
		}
	}

	cout << sum << endl;
	cout << result.str() << endl;
}

int main()  
{  
	invalidInput();
	return 0;
}
