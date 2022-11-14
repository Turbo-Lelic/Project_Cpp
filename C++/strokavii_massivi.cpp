#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int i = 0;
    char str[7] = {'A','l','e','x','e','y'};
    char str1[7] = "Alexey";
    char str2[7];
    char str3[7];
    str2[0] = 'A';
    str2[1] = 'l';
    str2[2] = 'e';
    str2[3] = 'x';
    str2[4] = 'e';
    str2[5] = 'y';

    cout << str << "\n" << str1 << "\n" << str2 << "\n";

    while(str[i] != '\0'){
        cout << str[i] << "\n";
        i++;
    }
    for (int j = 0; j < 7; j++){
        str3[j] += 'A';
        cout << str3[j] << "\n";
    }
    return 0;
} 