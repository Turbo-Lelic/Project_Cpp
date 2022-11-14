#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void f1(int *p1, int *p2);
void f2(int &p1);
void f3(int &p1, int &p2);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    int k1 = 1;
    int k2 = 2;
    int e = 0;
    int a1 = 1;
    int a2 = 2;

    // Передача параметра в кач. указателя

    f1(&k1, &k2);
    cout << "k1 = " << k1 << ", " << "k2 = " << k2 << "\n";

    // Передача параметра в кач. ссылки

    f2(e);
    cout << "e = " << e << "\n";

    f3(a1, a2);
    cout << "a1 = " << a1 << ", " << "a2 = " << a2 << "\n";

    return 0;
}
void f1(int *p1, int *p2){
    int temp = 0;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void f2(int &p1){
    p1 = 100;
}
void f3(int &p1, int &p2){
    int temp = 0;
    temp = p1;
    p1 = p2;
    p2 = temp;
}