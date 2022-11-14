#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int x = 0;
    char y = 'x';

    switch (x){
        case 0:
            cout << "x = 0\n";
        break;

        case 1:
            cout << "x = 1\n";
        break;

        case 2:
            cout << "x = 2\n";
        break;        

        default:
            cout << "x = default\n";
    }
    switch (y){
        case 'x':
            cout << "y = x\n";
        break;

        case 'y':
            cout << "y = y\n";
        break;

        case 'z':
            cout << "y = z\n";
        break;

        default:
            cout << "y = default\n";    
    }
    return 0;
}