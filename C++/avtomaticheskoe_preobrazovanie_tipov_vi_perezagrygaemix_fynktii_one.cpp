#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void f(int x);
void f(float x);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    short h = 30;

    f(20);
    f(20.0f);
    f(h);

    return 0;
}
void f(int x){
    cout << "int x = " << x << "\n";
}
void f(float x){
    cout << "float x = " << x << "\n";
}