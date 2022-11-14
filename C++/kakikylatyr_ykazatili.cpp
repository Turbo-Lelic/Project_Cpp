#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    int x1 = 0;
    int x2 = 0;
    char y1 = '0';

    int *ptr_x1;
    int *ptr_x2;
    char *ptr_y1;

    ptr_x1 = &x1;
    ptr_x2 = &x2;
    ptr_y1 = &y1;

    cout << "MAX NUM 2:" << "\n";
    cout << "x1 = ";
    cin >> x1; 
    cout << "x2 = ";
    cin >> x2;
    cout << "MAX ELEMENT 1:" << "\n";
    cout << "y1 = ";
    cin >> y1;

    if (*ptr_y1 == '+'){
        cout << "ID: " << ptr_x1 << " " << ptr_x2 << "\n";
        cout << "SUM: " << *ptr_x1 + *ptr_x2;
    }
    if (*ptr_y1 == '-'){
        cout << "ID: " << ptr_x1 << " " << ptr_x2 << "\n";
        cout << "SUM: " << *ptr_x1 - *ptr_x2;
    }
    if (*ptr_y1 == '*'){
        cout << "ID: " << ptr_x1 << " " << ptr_x2 << "\n";
        cout << "SUM: " << *ptr_x1 * *ptr_x2;
    }
    if (*ptr_y1 == '/'){
        cout << "ID: " << ptr_x1 << " " << ptr_x2 << "\n";
        cout << "SUM: " << *ptr_x1 / *ptr_x2;
    }
    return 0;
}