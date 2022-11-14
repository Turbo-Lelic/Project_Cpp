#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int f(int x);
int f(int x, int y);
float f(float x);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    cout << "int f(int x) = " << f(3) << "\n";
    cout << "int f(int x, int y) = " << f(3, 4) << "\n";
    cout << "float f(float x) = " << f(3.0f) << "\n";
    cout << "char f(char x) = " << f('!') << "\n";

    return 0;
}
int f(int x){
    return x;
}
int f(int x, int y){
    int z = x + y;

    return z;
}
float f(float x){
    return x;
}
char f(char x){
    return x;
}