#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> operator+(vector<string> vec1, vector<string> vec2) {
	vector<string> result;

	for (int i = 0; i < vec1.size();i++) {
		result.push_back(vec1[i] + " " + vec2[i]);
	}

	return result;
}

#endif // !SUMOFVECTORS_H
