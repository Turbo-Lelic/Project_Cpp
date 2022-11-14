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

    void print(){
        cout << "Возраст первого человека = " << age << "\n" << "Вес первого человека = " << weight << "\n" << "Имя первого человека = " << name << "\n";
    }
};

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    Human firstHuman;

    Human *ptr_firstHuman = &firstHuman;

    ptr_firstHuman->age = 12;
    ptr_firstHuman->weight = 50;
    ptr_firstHuman->name = "Алексей";

    ptr_firstHuman->print();

    return 0;
}