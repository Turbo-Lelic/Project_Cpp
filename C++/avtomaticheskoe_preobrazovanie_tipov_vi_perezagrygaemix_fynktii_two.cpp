#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

// void f(int x);
void f(int x, int y = 0);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    f(90);
    f(90, 56);

    return 0;
}
// void f(int x){
//     cout << "void f(int x) = " << x << "\n";
// }
void f(int x, int y){
    if (y == 0){
        cout << "void f(int x) = " << x << "\n";
    }
    if (y != 0){
        cout << "void f(int x, int y) = " << x << ", " << y << "\n";
    }
}