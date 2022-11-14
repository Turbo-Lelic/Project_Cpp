#include <iostream>
#include <stdio.h>
#include <locale>
#include <string>
using namespace std;

class Human{    
public:
    int age = 0;
    int weight = 0;
    string name = "None";
};

int main(void)
{
    setlocale(LC_ALL, "Russian");

    Human firstHuman;
    Human secondHuman;

    firstHuman.age = 20;
    firstHuman.weight = 60;
    firstHuman.name = "Иванов";
    
    secondHuman.age = 19;
    secondHuman.weight = 45;
    secondHuman.name = "Елизавета";

    cout << "Возраст первого человека = " << firstHuman.age << "\n" << "Вес первого человека = " << firstHuman.weight << "\n" << "Имя первого человека = " << firstHuman.name << "\n";
    cout << "_________________________________" << "\n";
    cout << "Возраст второго человека = " << secondHuman.age << "\n" << "Вес второго человека = " << secondHuman.weight << "\n" << "Имя второго человека = " << secondHuman.name << "\n";

    return 0;
}