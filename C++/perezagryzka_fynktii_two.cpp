#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

float f(float x);
int f(int x);

float a = 0.0;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    cin >> a;

    cout << "float f(float x) = " << f(a) << "\n";
    cout << "int f(int x) = " << f(a) << "\n";

    return 0;
}
int f(int x){
    return x;
}
float f(float x){
    return x;
}