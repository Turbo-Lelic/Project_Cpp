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

    int x = 10;
    int *ptrx;
    float f = 1.0;
    float *ptrf;
    char c[6] = "Semen";
    char *ptrc;

    ptrx = &x;
    ptrf = &f;
    ptrc = c;

    cout << "ptrx = " << ptrx << "\n";
    ptrx++;
    *ptrx = 10;
    cout << "ptrx = " << ptrx << "\n";
    ptrx+=2;
    *ptrx = 10;
    cout << "ptrx = " << ptrx << "\n";

    cout << "ptrf = " << ptrf << "\n";
    ptrf++;
    *ptrf = 1.0;
    cout << "ptrf = " << ptrf << "\n";
    ptrf+=2;
    *ptrf = 1.0;
    cout << "ptrf = " << ptrf << "\n";

    cout << "ptrc = " << ptrc << "\n";
    ptrc++;
    cout << "ptrc = " << ptrc << "\n";
    ptrc++;
    cout << "ptrc = " << ptrc << "\n";
    ptrc++;
    cout << "ptrc = " << ptrc << "\n";

    return 0;
}