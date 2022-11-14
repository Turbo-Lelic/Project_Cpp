#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int w = 0;

    cout << "Настройте значение w: ";
    cin >> w;

    if (w == 10){
        cout << "w = 10\n";
    }
    else if (w == 20){
        cout << "w = 20\n";
    }
    else if (w == 30){
        cout << "w = 30\n";
    }
    else if (w == 40){
        cout << "W = 40\n";
    }
    else{
        cout << "Error\n";
    }
    return 0;
}