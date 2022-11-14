#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 11; i++){
        cout << i << "\n";
    } 
    return 0;
}