#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int x = 2;
int f1();
int f2(int y);
int f3(int k, int o);
int f4(int k);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    int x = 50;
    int a = 1;

    int s = f1();
    int n = f2(5);
    int u = f3(5, 3);
    int h = f4(10);

    if (a == 1){
        int x = 0;
        x++;
        cout << x << "\n";
    }
    cout << s << "\n" << x << "\n" << n << "\n" << u << "\n" << h;
    return 0;
}
int f1(){
    int z = 0;
    z = x;
    return z;
}
int f2(int y){
    int n = 0;
    n = y + x;
    return n;
}
int f3(int k, int o){
    int m = k + o + x;
    if (m == 10){
        return 1;
    }
    else{
        return 0;
    }
}
int f4(int k){
    int t = 0;
    for (int i = 0; i < k; i++){
        t += i;
    }
}