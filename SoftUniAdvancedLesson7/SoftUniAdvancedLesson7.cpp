#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool parse(const char* buffer, int * result) {
    if(!*buffer) {
        return false;
	}

    int iRes = 0;

    while(*buffer) {
        if(*buffer >= '0' && *buffer <= '9') {
           iRes = iRes * 10 + (*buffer - '0');
        }
        else 
			return false;
        
        buffer++;
	}

	*result = iRes;
    return true;
}
void tryParse() {
    string a, b;
	cin >> a >> b;

    int iA = 0 , iB = 0;
    bool bA, bB;

	bA = parse(a.c_str(), &iA);
    bB = parse(b.c_str(), &iB);

    if(bA && bB) {
        cout << iA + iB << endl;
    }
    else {
        if(bA) {
            cout << iA << endl;
        }
        else{
            cout << "[error] " << a << endl;
        }
        
        if(bB){
            cout << iB << endl;
        }
        else {
            cout << "[error] " << b << endl;
        }
    }
}

void findMap() {
    string input;
    map<int, string> companies;
    while (cin >> input && input !="end")
    {
        int id;
        cin >> id;

        companies[id] = input;
    }
    
	int searchId;
    cin >> searchId;

    auto it = companies.find(searchId);
    if(it != companies.end()) {
        cout << it->second << ' ' << it->first <<  endl;
    }
    else {
        cout << "[not found]" << endl;
	}

}
void findMapAndPointers() {
    char buffer[1000] = { 0 };
	char* nextName = buffer;

    map<int, const char*> companies;

    string name;
    while (cin >> name && name != "end") {
        int id;
        cin >> id;
        strcpy(nextName, name.c_str());
        companies[id] = nextName;

        nextName += strlen(nextName) + 1;

    }

    int searchedId = 0;
    cin >> searchedId;

    auto it = companies.find(searchedId);
    if (it != companies.end()) {
        cout << it->second << ' ' << it->first;
    }
    else {
        cout << "[not found]";
    }
}

bool companiesCompare(const pair<int*, const char*>& a, const pair<int*, const char*>& b) {
   return (*a.first) < (*b.first);
}
void order() {
	char buffer[1000] = { 0 };
	int nextDataIdx = 0;

	vector<pair<int*, const char*>> companies;

    string name;
    while (cin >> name && name != "end") {
        int id;
        cin >> id;
        
		int* ptrId = (int *)(buffer + nextDataIdx);
		*ptrId = id;
        strcpy(buffer + nextDataIdx, name.c_str());

		companies.push_back(pair<int*, const char*>(ptrId,buffer + nextDataIdx));

		nextDataIdx += strlen(buffer + nextDataIdx) + 1;

    }

    sort(companies.begin(), companies.end(),companiesCompare);

    for(auto p: companies) {
        cout << p.second << ' ' << *p.first << endl;
	}
}

int main()
{
    order();
}

