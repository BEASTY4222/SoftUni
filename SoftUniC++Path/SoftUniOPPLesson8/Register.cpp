#include "Register.h"
#include <stdexcept>

// Constructor with initial size
Register::Register(size_t numCompanies)
    : numAdded(0)
{
    companiesArray = new Company[numCompanies];
}

// Copy constructor (deep copy)
Register::Register(const Register& other)
    : numAdded(other.numAdded)
{
    if (other.companiesArray) {
        companiesArray = new Company[numAdded];
        for (size_t i = 0; i < numAdded; i++) {
            companiesArray[i] = other.companiesArray[i];
        }
    }
    else {
        companiesArray = nullptr;
    }
}

// Copy assignment operator (deep copy, safe self-assignment)
Register& Register::operator=(const Register& other) {
    if (this != &other) {
        // free old memory
        delete[] companiesArray;

        numAdded = other.numAdded;
        if (other.companiesArray) {
            companiesArray = new Company[numAdded];
            for (size_t i = 0; i < numAdded; i++) {
                companiesArray[i] = other.companiesArray[i];
            }
        }
        else {
            companiesArray = nullptr;
        }
    }
    return *this;
}

// Destructor
Register::~Register() {
    delete[] companiesArray;
}

// Add a new company (resize array)
void Register::add(const Company& c) {
    Company* newArray = new Company[numAdded + 1];
    for (size_t i = 0; i < numAdded; i++) {
        newArray[i] = companiesArray[i];
    }
    newArray[numAdded] = c;

    delete[] companiesArray;
    companiesArray = newArray;
    numAdded++;
}

// Get company by id (guaranteed to exist per problem statement)
Company Register::get(int companyId) const {
    for (size_t i = 0; i < numAdded; i++) {
        if (companiesArray[i].getId() == companyId) {
            return companiesArray[i]; // return by value (safe copy)
        }
    }
    // Problem guarantees existence, but just in case:
    throw std::runtime_error("Company with given id not found");
}
