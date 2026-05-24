#include <iostream>
#include <math.h>
using namespace std;



void usdToBGN() {
    double usd;
    cin >> usd;
    double bgn = usd * 1.79549;
    
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << bgn << endl;
}

void radiansToDegrees() {
    double edge;
    cin >> edge;
    double degree = edge * 180 / 3.14;

    cout << round(degree) << endl;
}

void depositCalculator() {
    double deposit, yearlyLihva;
    int time;

    cin >> deposit >> time >> yearlyLihva;

    double lihva = deposit * (yearlyLihva * 0.01);
    double lihvaZaEdinMesec = lihva / 12;
    double result = deposit + time * lihvaZaEdinMesec;
    
    cout << result << endl;
}

void vacationBooksList() {
    int pages, pagesForOneHour, days;
    cin >> pages >> pagesForOneHour >> days;

    int timeForOneBook = pages / pagesForOneHour;
    int hoursNeeded = timeForOneBook / days;

    cout << hoursNeeded;

}

void suppliesForSchool() {
    int pens, markers, cleaningAgent, discount;
    cin >> pens >> markers >> cleaningAgent >> discount;

    double cost = pens * 5.80 + markers * 7.20 + cleaningAgent * 1.20;
    double discountOnCost = discount * 0.01;
    double finalCost = cost - (cost * discountOnCost);


    cout << finalCost;
}

void Repainting() {
    int nylon, paint, thinner, workHours;
    cin >> nylon >> paint >> thinner >> workHours;
    
    double costForMaterials = ((nylon + 2) * 1.5) + (((1 + 0.1) * paint) * 14.5) + (thinner * 5) + 0.40;
    double workCost = 0.30 * costForMaterials * workHours;

    cout << workCost + costForMaterials;

}

void foodDelivery() {
    int chikenMenu, fishMenu, vegeMenu;
    cin >> chikenMenu >> fishMenu >> vegeMenu;

    double bill = chikenMenu * 10.35 + fishMenu * 12.4 + vegeMenu * 8.15;
    double desert = bill * 0.2;

    cout << bill + desert + 2.50 << endl;
}

void basketballEquipment() {
    int tax;
    cin >> tax;

    double shoes = tax * 0.6;
    double set = shoes * 0.8;
    double ball = set * 0.25;
    double acc = ball * 0.20;

    cout << tax + shoes + set + ball + acc;

}

void fishTank() {
    int lenght, width, height;
    double takenPercentage;
    cin >> width >> lenght >> height >> takenPercentage;

    double volumeInLitres = 0.001 * width * lenght * height;
    double freeVolume = volumeInLitres - 0.01 * takenPercentage * volumeInLitres;

    cout << freeVolume;

}
int main()
{
    fishTank();


}


