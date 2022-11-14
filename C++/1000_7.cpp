#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int x = 1000;

    while (x > 6){
        x = x - 7;
        cout << x << "\n";
    }
    if (x == 6){
        cout << "I DED INTEL SID\n";
    }
    return 0;
}