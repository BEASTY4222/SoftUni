#pragma once

#include <string>
#include <sstream>

template <typename T> class Parser {

	std::istream& is;
	std::string stopLine;

public:
	Parser(std::istream& nis, const std::string& nStopLine)
		: is(nis), stopLine(nStopLine) {}

	bool readNext(T& elem) {
		std::string curLine;
		getline(is, curLine);
		if (curLine == stopLine) {
			return false;
		}

		std::istringstream istr(curLine);
		istr >> elem;

		return true;
		
	}

};