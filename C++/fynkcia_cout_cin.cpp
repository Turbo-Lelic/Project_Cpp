#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int x1 = 2;
    
    cout << "Введите значение переменной x1: ";
    cin >> x1;
    cout << "x1 = " << x1 << "\n";
     
    return 0;
}