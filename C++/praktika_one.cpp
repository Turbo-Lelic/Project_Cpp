#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int a[5] = {1, 2, 3, 4, 5};

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    for (int i = 0; i < 5; i++){
        a[i] = i + 1;
    }
    for (int j = 0; j < 5; j++){
        cout << "Введите a[" << j << "] = ";
        cin >> a[j];
    }
    for (int l = 0; l < 5; l++){
        cout << a[l];
    }
    cout << "\n";
    return 0;
}