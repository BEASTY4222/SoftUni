#pragma once

#include "Company.h"

#include <vector>

Company* find(const std::vector<Company*> &companies,const int &searchId) {
	for (std::vector<Company*>::const_iterator it = companies.begin();
		it != companies.end(); it++) {
		if ((*it)->getId() == searchId) {
			return (*it);
		}
	}
	return nullptr;
}
