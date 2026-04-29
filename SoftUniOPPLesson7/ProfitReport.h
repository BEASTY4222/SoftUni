#pragma once

#include <string>
#include <map>
#include <sstream>
#include "Company.h"
#include "ProfitCalculator.h"

inline std::string getProfitReport(Company* fromInclusive, Company* toInclusive, const std::map<int, ProfitCalculator>& calculators) {
    std::ostringstream report;

    for (Company* current = fromInclusive; current <= toInclusive; ++current) {
        int companyId = current->getId();
        std::string companyName = current->getName();

        auto it = calculators.find(companyId);
        if (it != calculators.end()) {
            int profit = it->second.calculateProfit(*current);
            report << companyName << " = " << profit << "\n";
        }
        else {
            report << companyName << " = " << 0 << "\n"; // fallback if no calculator found
        }
    }

    return report.str();
}
