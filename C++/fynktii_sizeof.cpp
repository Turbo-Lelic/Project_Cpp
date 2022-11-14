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
    cout << str1 << "\n\n";
    
    strcat(str1, str2);
    cout << str1 << "\n\n";

    cout << strcmp(str3, str4) << "\n";

    if (strcmp(str3, str4) !=0 ){
        cout << "=\n\n";
    }
    else{
        cout << "!=\n\n";
    }
    cout << "strlen str1 = " << strlen(str1) << "\n" << "strlen str2 = " << strlen(str2) << "\n" << "strlen str3 = " << strlen(str3) << "\n" << "strlen str4 = " << strlen(str4) << "\n\n";
    cout << "sizeof str1 = " << sizeof(str1) << "\n" << "sizeof str2 = " << sizeof(str2) << "\n" << "sizeof str3 = " << sizeof(str3) << "\n" << "sizeof str4 = " << sizeof(str4) << "\n";
    return 0;
}