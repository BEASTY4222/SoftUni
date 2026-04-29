#include <iostream>

void SoftUniTask1()
{
    std::cout << "Hello SoftUni";

}

void SoftUniTask2()
{
    std::cout << 1 << std::endl;
    std::cout << 2 << std::endl;
    std::cout << 3 << std::endl;
    std::cout << 4 << std::endl;
    std::cout << 5 << std::endl;
    std::cout << 6 << std::endl;
    std::cout << 7 << std::endl;
    std::cout << 8 << std::endl;
    std::cout << 9 << std::endl;
    std::cout << 10 << std::endl;

}
void SoftUniTask3()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a * b;

}
void SoftUniTask4() {
    double inches;

    std::cin >> inches;
    std::cout << inches * 2.54;
}
void SoftUniTask5() {
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!";

}
void SoftUniTask6() {
    std::string firstName, lastName, town;
    int age;
    std::cin >> firstName >> lastName >> age >> town;
    std::cout << "You are " << firstName << ' ' << lastName <<  ", " << "a " << age << "-years old old person from " << town << '.';

}
void SoftUniTask7() {
    std::string name;
    int projects;
    std::cin >> name >> projects;
    std::cout << "The architect "<< name <<" will need " << projects * 3 << " hours to complete " << projects << " project / s.";

}
void SoftUniTask8() {
    int countDog, countCat;
    double sum;
    std::cin >> countDog >> countCat;
    sum = (countDog * 2.50) + (countCat * 4);
    std::cout << sum << " lv.";

}
void SoftUniTask9() {
    double space;
    std::cin >> space;

    double priceBeforeDiscount = space * 7.61;
    double discount = 0.18 * priceBeforeDiscount;

    double priceAfterDiscount = priceBeforeDiscount - discount;

    std::cout << "The final price is: " << priceAfterDiscount << " lv." << std::endl;
    std::cout << "The discount is: " << discount << " lv.";

}

int main() {


}
