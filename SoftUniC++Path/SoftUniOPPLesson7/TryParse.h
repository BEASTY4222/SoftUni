#pragma once

#include <sstream>


bool tryParse(std::string &text,int &a) {
	std::stringstream istr(text);

	if (istr >> a) {
		return true;
	}
	return false;
}
