#pragma once

#include <vector>
#include <algorithm>

class OrderedInserter {

	std::vector<const Company*> &companies;

public:
	OrderedInserter(std::vector<const Company*> &vec):
	companies(vec){}

	void insert(const Company* c) {
		companies.push_back(c);
		std::sort(companies.begin(), companies.end(), []
			(const Company* &a, const Company* &b) {
				return a->getId() < b->getId();
			}
		);
	}
};