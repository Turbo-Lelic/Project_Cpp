#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void f(float x);
void f(double x);
void f(int x);
void f2(char x);
void f2(unsigned char x);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    f(40);
    f(40.5);
    f(40.67f);
    f2('x');

    return 0;
}
void f(float x){
    cout << "float x = " << x << "\n";
}
void f(double x){
    cout << "double x = " << x << "\n";
}
void f(int x){
    cout << "int x = " << x << "\n";
}   
void f2(char x){
    cout << "char x = " << x << "\n";
}
void f2(unsigned char x){
    cout << "unsigned char x = " << x << "\n";
}
