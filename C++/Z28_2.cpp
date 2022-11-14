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

    for (int i = 0; i < *ptr_x; i++){
        if (i % 2 == 0){
            cout << "Четное число" << "\n";
        }
        else{
            cout << "Нечетное число" << "\n";
        }
    }

}