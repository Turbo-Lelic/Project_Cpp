#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void func(int *p);
void func2(int *p);
void func_str(char *c);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);
    
    int x = 0;
    int d = 0;
    int *ptr_p;
    char str[] = "straoka";

    ptr_p = &x;

    func2(&d);
    func(ptr_p);

    cout << x << "\n" << d << "\n";
    func_str(str);

    return 0;
}
void func(int *p)
{
    *p = 10;
}
void func2(int *p)
{
    *p = 55;
}
void func_str(char *c)
{
    while(*c){ 
        cout << *c;
        c++;
    }
}