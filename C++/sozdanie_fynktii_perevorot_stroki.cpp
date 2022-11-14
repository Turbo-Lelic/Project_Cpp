#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void revers_str(char *s);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    char str[] = "12345";

    revers_str(str);

    return 0;
}
// Пример переворота строки
void revers_str(char *s){
    if (*s != '\0'){
        revers_str(s + 1);
    }
    else{
        return;
    }
    cout << *s;
}