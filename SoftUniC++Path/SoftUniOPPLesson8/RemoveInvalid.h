#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"

// Place your code here
void removeInvalid(std::list<Company*>& companies) {
    for (auto it = companies.begin(); it != companies.end(); ) {
        if (*it == nullptr || (*it)->getId() < 0) {
            delete* it;               // Free the memory
            it = companies.erase(it); // Remove from list and update iterator
        }
        else {
            ++it; // Move to next only if not erased
        }
    }
}


#endif // !REMOVE_INVALID_H

