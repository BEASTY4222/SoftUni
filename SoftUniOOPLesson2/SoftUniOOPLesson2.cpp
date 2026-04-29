#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <list>
#include <iomanip>
#include <map>

using namespace std;

class sentanceShifter {
    int shifts = 0;
    string line;
    list<string> sentance;

    public:
        void read();

        void getShiftedSentance(); 

        void printSentance();
        
};
void sentanceShifter::read() {
    getline(cin, line);
    istringstream getSentance(line);
    while (getSentance >> line) {
        sentance.push_back(line);
    }

    cin >> shifts;
}
void sentanceShifter::getShiftedSentance() {
    read();

    while (shifts--){
        string firstWord = sentance.front();
        string lastWord = sentance.back();
        sentance.pop_back();
        sentance.push_front(lastWord);
    }

    printSentance();
}
void sentanceShifter::printSentance() {
    for (list<string>::iterator it = sentance.begin(); it != sentance.end(); it++) {
        cout << *it << endl;
    }
}

//√((x2 - x1)² + (y2 - y1)²)
class cordinates {
    int x, y;

    public:
        void readCords();
        int getX() const;
        int getY() const;
};
int cordinates::getX () const {return x;}
int cordinates::getY() const {return y;}
void cordinates::readCords() {
    cin >> x >> y;
}

/*
    DistanceCalculator d;
    cordinates first;
    cordinates second;

    first.readCords();
    second.readCords();

    d.calcDistance(first, second);
*/
class DistanceCalculator { 
    double distance = 0;

    public:
        void calcDistance(cordinates&, cordinates&);
};
void DistanceCalculator::calcDistance(cordinates& first, cordinates& second) {
    distance = sqrt(pow(second.getX() - first.getX(), 2) + pow(second.getY() - first.getY(), 2));

    cout << fixed << setprecision(3) << distance << endl;
}

class sales {
    string town, product;
    double price = 0,total = 0;
    double quantity = 0, numberOfSales = 0;
    map<string, double> salesByTown;

    public:
        void calcSales();
        void printSalesByTown();
};
void sales::calcSales(){
    cin >> numberOfSales;
    while (numberOfSales--) {
        cin >> town >> product >> price >> quantity;
        
        salesByTown[town] += quantity * price;
    }
}
void sales::printSalesByTown() {
    calcSales();

    for (map<string, double>::iterator it = salesByTown.begin(); it != salesByTown.end();it++) {
        cout << fixed << setprecision(2);
        cout << it->first << " -> " << it->second << endl;
    }
}

class totalAvrageOfStudents {
    string studentName, studentSurname;
    double totalAvarage = 0, grade = 0;
    int numberOfStudents = 0;
    vector<string> wholeStudentNames;
    vector<double> allGrades;
    

    public:
        void read();
        void calcAvarage();
        void print() const;
};
void totalAvrageOfStudents::read() {
    cin >> numberOfStudents;
    while (numberOfStudents--) {
        cin >> studentName >> studentSurname >> grade;

        wholeStudentNames.push_back(studentName + " " + studentSurname);
        allGrades.push_back(grade);
    }
}
void totalAvrageOfStudents::calcAvarage() {
    read();
    if (wholeStudentNames.empty()) {
        cout << "Invalid input" << endl;
        return;
    }

    double sumOfGrades = 0;
    for (const double grade : allGrades) {
        sumOfGrades += grade;
    }
    totalAvarage = sumOfGrades / allGrades.size();

    print();
}
void totalAvrageOfStudents::print() const {
    cout << fixed << setprecision(1);
    for (int i = 0; i < wholeStudentNames.size() || i < allGrades.size();i++) 
        cout << wholeStudentNames[i] << " " << allGrades[i] << endl;
    
    cout << fixed << setprecision(0) << totalAvarage << endl;
}

int main()
{
    totalAvrageOfStudents t;

    t.calcAvarage();

    return 0;
}
