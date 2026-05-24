#ifndef MIN_BY_H
#define MIN_BY_H

#include <sstream>
#include <vector>

// Place your code here
template<typename f>
std::string minBy(const std::vector<std::string> &values, f compFunc) {
	std::string minElem = values[0];


	for (const std::string &elem : values) {
		if (compFunc(elem,minElem)) {
			minElem = elem;
		}
	}


	return minElem;
}

#endif // !MIN_BY_H

