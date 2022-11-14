#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

char str1[12];
char str2[8] = " Ivanov";
char str3[4] = "abc";
char str4[4] = "abc";

int main(void)
{
    setlocale(LC_ALL, "Russian");

    strcpy(str1, "Alex");
    cout << str1 << "\n";
    
    strcat(str1, str2);
    cout << str1 << "\n";

    cout << strcmp(str3, str4) << "\n";

    if (strcmp(str3, str4) !=0 ){
        cout << "=\n";
    }
    else{
        cout << "!=\n";
    }
    return 0;
}