#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

string earlyLexicographic(istringstream& line) {
	string word, firstWord;
	if (line >> firstWord) { // Initialize with the first word
		while (line >> word) {
			if (word < firstWord) { // Use < for earliest lexicographically
				firstWord = word;
			}
		}
		return firstWord;
	}
	return ""; // Return empty if no words
}
string shortestString(istringstream &line) {
	string word, shortString;
	while (line >> word)
	{
		if (word.length() < shortString.length()) {
			shortString = word;
		}
	}

	return shortString;
}
string longestString(istringstream &line) {
	string word ,longest;
	while (line >> word)
	{
		if(word.length() > longest.length()) {
			longest = word;
		}
	}

	return longest;
}
void minBy() {
	string line;
	int func;
	getline(cin, line);
	cin >> func;
	istringstream iss(line);

	string(*funcPtr)(istringstream&) = nullptr;

	switch (func) {
	case 1:
		funcPtr = earlyLexicographic;
		break;
	case 2:
		funcPtr = shortestString;
		break;
	case 3:
		funcPtr = longestString;
		break;

	}

	cout << funcPtr(iss) << endl;
}

void removeInvalid() {
    map<string, int> companies;
    vector<string> order;
    string currWord;
    int currId;

    while (cin >> currId >> currWord && currWord != "end") {
        companies[currWord] = currId;
        order.push_back(currWord);
    }

    for (const auto& word : order) {
        auto it = companies.find(word);
        if (it != companies.end() && it->second > 0) {
            cout << it->second << " " << it->first << endl;
        }
    }
}

int main()
{
	removeInvalid();
}

