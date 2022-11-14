#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int x = 0;
    float x1 = 3.14;
    char x2 = 'h';
    bool x3 = true;

    cout << "Сохраните в int = x: ";
    cin >> x;
    cout << "x = " << x << "\n";

    cout << "Сохраните в float = x1: ";
    cin >> x1;
    cout << "x1 = " << x1 << "\n";

    cout << "Сохраните в char = x2: ";
    cin >> x2;
    cout << "x2 = " << x2 << "\n";
    
    cout << "Сохраните в bool = x3: ";
    cin >> x3;
    cout << "x3 = " << x3 << "\n"; 
    
    return 0;
}