#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template <typename T>
std::vector<T>& operator<<(std::vector<T>& vec, const T& value) {
	vec.push_back(value);
	return vec;
}

ostream& operator<<(ostream& out, std::vector<string>& vec) {
	for (const string elem : vec) {
		out << elem << endl;
	}

	return out;
}

std::string operator+(std::string line, int number) {
	ostringstream result;
	result << line << number;
	
	return result.str();
}

#endif // !OPERATORS_H
