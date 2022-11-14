#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    char x[5] = {"123456789"};
    char *start;
    char *end;
    int x_len = strlen(x);
    int temp = 0;
    start = x;
    end = &x[x_len - 1];

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    cout << x << "\n";
    return 0;
}