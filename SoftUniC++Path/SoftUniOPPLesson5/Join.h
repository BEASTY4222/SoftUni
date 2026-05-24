#pragma once

#include <string>
#include <vector>
#include <sstream>


template<class t>
std::string join(const std::vector<t> &things, const std::string &joinElem) {
	std::string joinedStr;
	bool first = true;
	size_t idx = 0;

	for (auto& elem : things) {
		std::string test;
		std::ostringstream oss;
		oss << elem;
		if (idx == things.size() - 1)
			joinedStr += oss.str();
		else
			joinedStr += oss.str() + joinElem;

		oss.clear();
		idx++;
	}

	return joinedStr;
}
