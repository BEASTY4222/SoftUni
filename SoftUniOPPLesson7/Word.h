#pragma once
#include <map>
#include <string>
class Word {
	std::string str;
	static std::map<std::string, int> count;

public:
	Word(const std::string &wordStr): str(wordStr) {
		count[str]++;
	}

	std::string getWord() const {return str;}
	int getCount() const {
		int countStr = count[str];
		count[str] = 0;

		return countStr;
	}

	bool operator <(const Word &b) const {
		return str < b.getWord();
	}
};