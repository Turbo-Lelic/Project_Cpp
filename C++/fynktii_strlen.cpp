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
    cout << "str1 = " << strlen(str1) << "\n" << "str2 = " << strlen(str2) << "\n" << "str3 = " << strlen(str3) << "\n" << "str4 = " << strlen(str4) << "\n";
    return 0;
}