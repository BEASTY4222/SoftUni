#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;


void shapes() {
    string shape;
    double result;
    cin >> shape;

    if (shape == "square")
    {
        double a;
        cin >> a;

        result = a * a;
    }
    else if (shape == "rectangle") {
        double a, b;
        cin >> a >> b;

        result = a * b;
    }
    else if (shape == "circle") {
        double r;
        cin >> r;

        result = M_PI * pow(r, 2);
    }
    else if (shape == "triangle") {
        double a, h;
        cin >> a >> h;

        result = a * h / 2;
    }


    cout.setf(ios::fixed);
    cout.precision(3);
    
    cout << result;

}

void speed() {
    double speed;
    string speedInText;
    cin >> speed;

    if (speed <= 10.0)
    {
        speedInText = "slow";
    }
    else if (speed <= 50.0) {
        speedInText = "average";
    }
    else if (speed <= 150.0) {
        speedInText = "fast";
    }
    else if(speed <= 1000.0)
    {
        speedInText = "ultra fast";
    }
    else
    {
        speedInText = "extremely fast";
    }
    cout << speedInText;
}

void number100To200() {
    int num;
    cin >> num;

    if (num < 100)
    {
        cout << "Less than 100";
    }
    else if (num >= 100 && num < 200)
    {
        cout << "Between 100 and 200";
    }
    else if (num >= 200)
    {
        cout << "Greater than 200";
    }
}

void checkPass() {
    string pass;
    cin >> pass;

    if (pass == "s3cr3t!P@ssw0rd")
    {
        cout << "Welcome";
    }
    else {
        cout << "Wrong password!";
    }
}


void evenOrOdd() {
    int num;
    cin >> num;

    if (num % 2 == 0)
    {
        cout << "even";
    }
    else {
        cout << "odd";
    }
}

void greaterNumber() {
    int num1, num2;
    cin >> num1 >> num2;

    if (num1 > num2)
    {
        cout << num1;
    }
    else {
        cout << num2;
    }
}

void exellentGrade() {
    double grade;
    cin >> grade;

    if (grade >= 5.50)
    {
        cout << "Excellent!";
    }
}



int main()
{
    std::cout << "Hello World!\n";
}

