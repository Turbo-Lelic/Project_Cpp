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

    char str[80] = "Ivanov Sergey Petro";
    char *ptr;

    ptr = str;

    for(int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i])) 
        {
            str[i] = tolower(str[i]);
        }
        else if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    cout << "str = " << str << "\n";
    while(*ptr)
    {
        if (isupper(*ptr)) 
        {
            *ptr = tolower(*ptr);
        }
        else if (islower(*ptr))
        {
            *ptr = toupper(*ptr);
        }
        ptr++;
    }
    cout << "ptr = " << str << "\n";
    return 0;
}