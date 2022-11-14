#include <Windows.h>
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

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    Human firstHuman;
    Human secondHuman;

    Human *ptr_firstHuman = &firstHuman;
    Human *ptr_secondHuman = &secondHuman;

    ptr_firstHuman->age = 20;
    ptr_firstHuman->weight = 60;
    ptr_firstHuman->name = "Иванов";

    ptr_secondHuman->age = 19;
    ptr_secondHuman->weight = 45;
    ptr_secondHuman->name = "Елизавета";

    cout << "Возраст первого человека = " << ptr_firstHuman->age << "\n" << "Вес первого человека = " << ptr_firstHuman->weight << "\n" << "Имя первого человека = " << ptr_firstHuman->name << "\n";
    cout << "_________________________________" << "\n";
    cout << "Возраст второго человека = " << ptr_secondHuman->age << "\n" << "Вес второго человека = " << ptr_secondHuman->weight << "\n" << "Имя второго человека = " << ptr_secondHuman->name << "\n";

    return 0;
}