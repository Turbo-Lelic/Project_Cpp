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

    char n[20];
    int x[20];
    char *ptr_n = n;
    int *ptr_x = x;

    *(ptr_n + 1) = '1';
    *(ptr_n + 2) = '2';
    *(ptr_n + 3) = '3';
    *(ptr_x + 1) = 1;
    *(ptr_x + 2) = 2;
    *(ptr_x + 3) = 3; 

    cout << *(ptr_n + 1) << "\n";
    cout << *(ptr_x + 1) << "\n";

    return 0;
}