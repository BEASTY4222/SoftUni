#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void countRealNumbers() {
    string line;
    getline(cin, line);
    stringstream mainLine(line);

    map<double, unsigned> numbers;

    double currNum;
    while (mainLine >> currNum)
        numbers[currNum]++;

    for (const pair<double, unsigned>& n : numbers)
        cout << n.first << " -> " << n.second << endl;
}

void oddOccurrences() {
    set<string> oddOnes;
    vector<string> order;
    string bufferLine;
	string word;

    getline(cin, bufferLine);

    transform(bufferLine.begin(), bufferLine.end(), bufferLine.begin(), ::tolower);

    istringstream mainLIne(bufferLine);


    while (mainLIne >> word) {
		set<string>::iterator it = oddOnes.find(word);
        if(it != oddOnes.end()) {
            oddOnes.erase(it);
        } else {
            oddOnes.insert(word);
		}
    }

    istringstream lineReadyToPrint(bufferLine);
	bool first = true;
	while(lineReadyToPrint >> word) 
        if (oddOnes.find(word) != oddOnes.end()) {
            if(first) 
                first = false;
             else 
                cout << ", ";
			
			cout << word;
            oddOnes.erase(word);
            
        }
            
    
	

}

void biggestThree() {
	set<double> numbers;
	string bufferLine;
	getline(cin, bufferLine);

	istringstream mainLine(bufferLine);

	double currNum;
    while (mainLine >> currNum) {
		numbers.insert(currNum);    
    }

	set<double>::iterator it = numbers.end();
    it--;

    if (numbers.size() < 3) {
        for (int i = numbers.size(); i ; i--) {
            cout << *it << " ";
            it--;
        }
		return;
    }

    for(int i = numbers.size(); i > numbers.size() - 3; i--) {
        cout << *it << " ";
        it--;
	}


}

void shortWords() {
	set<string> words;
    string bufferLine;
    string word;

    getline(cin, bufferLine);

    transform(bufferLine.begin(), bufferLine.end(), bufferLine.begin(), ::tolower);

	istringstream mainLine(bufferLine);

    while (mainLine >> word)
    {
        words.insert(word);
    }

	set<string>::iterator it = words.begin();
	bool first = true;
    while (it != words.end()) {
        if (it->length() < 5) {
            if(first)
                first = false;
            else
				cout << ", ";
			cout << *it;
        }
        it++;
	}
}

void sortNumbers() {
    set<double> numbers;
    string bufferLine;
    double num;
    getline(cin, bufferLine);

    transform(bufferLine.begin(), bufferLine.end(), bufferLine.begin(), ::tolower);

    istringstream mainLine(bufferLine);

    while (mainLine >> num)
    {
        numbers.insert(num);
    }

    // <= 
	set<double>::iterator it = numbers.begin();
	bool first = true;
    while (it != numbers.end()) {
        if (first)
            first = false;
        else
			cout << " <= ";
        cout << *it;
		it++;
    }
	cout << endl;
}

void squares() {
	multiset<int, greater<int>> numbers;
    int currNum;
	string bufferLine;
	getline(cin, bufferLine);

    istringstream mainLine(bufferLine);

    while (mainLine >> currNum) 
        numbers.insert(currNum);
	
    for (int curr : numbers) {
		double d = sqrt(curr);
        if(trunc(d) == d) {
			cout << curr << " ";
		}
    }
}

void miners() {
    map<string, unsigned> miners;
	vector<string> names;
    string name;
    unsigned amount;
    while (true) {
        cin >> name;
        if(name == "stop") 
            break;
		
		cin >> amount;
        if (miners.find(name) == miners.end()) {
			names.push_back(name);
            miners[name] = amount;
        }
        else 
            miners[name] += amount;
        
    }

    for (const string& name : names) {
		cout << name << " -> " << miners[name] << endl;
       
	}
}

int main()
{
    miners();
}

