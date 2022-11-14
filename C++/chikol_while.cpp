#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < 11){
        cout << i << "\n";
        i++;    
    }
    cout << "\n";
    while (j < 100){
        if (j == 16){
            break;
        }
        cout << j << "\n";
        j++;
    }
    cout << "\n";
    while (true){
        if (k == 16){
            break;
        }
        cout << k << "\n";
        k++;    
    }
    return 0;
}