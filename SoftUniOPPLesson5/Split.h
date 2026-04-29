#pragma once
#include <sstream>
#include <vector>

template<class t> 
std::vector<t> split(const std::string &line, const char &se) {
	std::istringstream istr(line);
	std::string elem;
	std::vector<t> result;

	while (std::getline(istr,elem,se)){
		std::istringstream convert(elem);
		t word;
		convert >> word;

		result.push_back(word);
	}

	return result;
}

