#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int factrec(int n);
int facti(int n);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    cout << factrec(4) << "\n";
    cout << facti(4) << "\n";

    return 0;
}
// Первый вариант найти факториал
int factrec(int n){
    int f = 0;
    if (n == 1){
        return 1;
    } 
    f = factrec(n - 1) * n;
    return f;
}
// Второй вариант найти факториал
int facti(int n){
    int f = 1;
    for (int i = 1; i <= n; i++){
        f = f * i;
    }
    return f;
}