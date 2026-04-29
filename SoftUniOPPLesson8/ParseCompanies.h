#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"

#include <sstream>
#include <vector>
#include <set>

// Place your code here
template<typename f>
Company* parseUniqueCompanies(std::string input,int &numCompanies,f func) {
    std::stringstream istr(input);
    int id;
    std::string name;

    std::vector<Company> temp;
    std::set<std::string> ids;

    while (istr >> id >> name) {
        Company c(id, name);
        std::string uniqueName = func(c);

        std::pair<std::set<std::string>::iterator, bool>
            uniqueResult = ids.insert(uniqueName);

        if (uniqueResult.second == false) {
            continue;
        }

        temp.push_back(c);
        
    }

    numCompanies = temp.size();
    Company* arr = new Company[numCompanies];
    for (int i = 0; i < numCompanies; i++) {
        arr[i] = temp[i];
    }


    return arr;
}

#endif // !PARSE_COMPANIES_H
