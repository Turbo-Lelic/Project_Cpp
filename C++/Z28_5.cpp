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

    int x1, x2, x3 = 0;
    int *ptr_x1 = &x1;
    int *ptr_x2 = &x2;
    int *ptr_x3 = &x3;

    cin >> x1 >> x2 >> x3;

    if (*ptr_x1 != *ptr_x2 && *ptr_x1 != *ptr_x3){
        cout << *ptr_x1;
    }
    if (*ptr_x2 != *ptr_x1 && *ptr_x2 != *ptr_x3){
        cout << *ptr_x2;
    }
    if (*ptr_x3 != *ptr_x1 && *ptr_x3 != *ptr_x2){
        cout << *ptr_x3;
    }
    return 0;
}