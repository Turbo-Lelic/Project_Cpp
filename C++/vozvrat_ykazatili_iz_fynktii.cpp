#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <locale>
using namespace std;
 
const char *get_substr(const char *sub, const char *stroka);
 
int main(void)
{
    setlocale(LC_ALL, "Russian");
 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    char str[] = "Ivanov Alex Aleksandrovich";
    char substr[] = "Alex";
 
    cout << get_substr("Alex", "Ivanov Alex Aleksandrovich");
 
    return 0;
}
const char *get_substr(const char *sub, const char *stroka)
{
    const char *k1,*k2,*n;
 
    for (int i = 0; stroka[i] != '\0'; i++){
        k1 = &stroka[i];
        n = k1;
        k2 = sub;
 
        while (*k2 && *k2 == *k1){
            k1++;
            k2++;
        }
        if (*k2 == '\0')
            return n;
    }
    return 0;
}