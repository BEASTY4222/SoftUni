#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void lucnhBreak() {
    string name;
    int epTime, breakTime;
    getline(cin, name);
    cin >> epTime >> breakTime;

    double timeForLunch = breakTime * 0.125;
    double timeForRest = breakTime * 0.25;
    double neededRest = breakTime - (timeForLunch + timeForRest);

    if (epTime <= neededRest)
    {
        cout << "You have enough time to watch " << name << " and left with " << ceil(neededRest - epTime) << " minutes free time.";
    }
    else
    {
        cout << "You don't have enough time to watch " << name << ", you need " << ceil(epTime - neededRest) << " more minutes.";
    }
}

void shopping() {
    int gpu, cpu, ram;
    double budget;
    cin >> budget >> gpu >> cpu >> ram;

    double gpuCost = gpu * 250;
    double cpuCost = gpuCost * 0.35 * cpu;
    double ramCost = gpuCost * 0.10 * ram;
    double totalCost = gpuCost + cpuCost + ramCost;

    if (gpu > cpu)
    {
        totalCost -= 0.15 * totalCost;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (totalCost <= budget)
    {
        cout << "You have " << budget - totalCost << " leva left!";
    }
    else {
        cout << "Not enough money! You need " << totalCost - budget << " leva more!";
    }
}

void worldSwimmingRecord() {
    double a, b, c;
    cin >> a >> b >> c;

    double v = b * c + floor(b / 15) * 12.5;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (v < a)
    {
        cout << "Yes, he succeeded! The new world record is " << v << "  seconds.";
    }
    else {
        cout << "No, he failed! He was " << v - a << "seconds slower.";
    }

}

void godzillaVsKong() {
    double budget, pricePerExtraClothes;
    int extrasCount;
    cin >> budget >> extrasCount >> pricePerExtraClothes;

    double priceForClothes = pricePerExtraClothes * extrasCount;
    double decor = budget * 0.1;

    if (extrasCount >= 150)
    {
        priceForClothes -= 0.1 * priceForClothes;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (priceForClothes + decor <= budget)
    {
        cout << "Action!" << endl;
        cout << "Wingard starts filming with " << budget - (priceForClothes + decor) << " leva left.";
    }
    else
    {
        cout << "Not enough money!" << endl;
        cout << "Wingard needs " << (priceForClothes + decor) - budget << " leva more.";
    }
}

void toyShop() {
    double tripCost;
    int puzzels, dolls, bears, minions, trucks;
    cin >> tripCost >> puzzels >> dolls >> bears >> minions >> trucks;

    double profit = puzzels * 2.6 + dolls * 3 + bears * 4.1 + minions * 8.2 + trucks * 2;

    if (puzzels + dolls + bears + minions + trucks >= 50) {
        profit = 0.75 * profit;
    }

    profit = 0.9 * profit;


    cout.setf(ios::fixed);
    cout.precision(2);

    if (profit >= tripCost) {
        cout << "Yes! " << profit - tripCost << " lv left.";
    }
    else
    {
        cout << "Not enough money! " << tripCost - profit << " lv needed.";
    }
}

void timePlus15Minutes() {
    int hours, minuts;
    cin >> hours >> minuts;

    minuts += 15;

    if (minuts >= 60) {
        hours += 1;
        minuts -= 60;
    }


    if (hours == 24)
    {
        hours = 0;
    }
    

    if (minuts < 10) {
        cout << hours << ":0" << minuts;
    }
    else
    {
        cout << hours << ":" << minuts;
    }

}

void bonusScore() {
    int score;
    double bonus = 0.0;
    cin >> score;

    if (score <= 100)
    {
        bonus += 5;
    }else if (score > 1000) {
        bonus += 0.1 * score;
    }
    else
    {
        bonus += 0.2 * score;
    }

    if (score % 2 == 0) {
        bonus += 1;
    }
    else if (score % 10 == 5) {
        bonus += 2;
    }

    cout << bonus << endl;
    cout << score + bonus << endl;
}

void sumSeconds() {
    int first, second, third;
    cin >> first >> second >> third;

    int sum = first + second + third;

    int minuts = sum / 60;
    int seconds = sum % 60;


    if (seconds < 10)
    {
        cout << minuts << ":0" << seconds;
    }
    else {
        cout << minuts << ":" << seconds;
    }
}


int main()
{
    lucnhBreak();
}
