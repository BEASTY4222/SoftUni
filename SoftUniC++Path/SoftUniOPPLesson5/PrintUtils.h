#pragma once

#include <iostream>
#include <string>
#include <sstream>

template <typename t>
void printContainer(typename t::iterator beg, typename t::iterator end) {
	for (; beg != end;beg++) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;
}