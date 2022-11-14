#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    int x = 0;
    int *ptr_x = &x;

    cin >> x;

    switch (*ptr_x)
    {
    case 365:
        cout << "Это обычный год";
        break;

    case 366:
        cout << "Это високосный год";
        break;
    }
    return 0;
}