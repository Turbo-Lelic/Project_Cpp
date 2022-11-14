#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void func(int v, int n);
void func2();
int func3(int h, int k);
void func4(int w, int o);
void func5(int n, int u);
void func6(int j, int i);

int main(void)
{   
    setlocale(LC_ALL, "Russian");

    int a = 5;
    int b = 57;
    int r = func3(a, b);

    func(a, b);
    func2();
    cout << r << "\n";
    func4(a, b);
    cout << "\n";
    func5(a, b);
    func6(a, b);

    return 0;
}
void func(int v, int n)
{
    int z = v + n;
    cout << z << "\n";
}
void func2()
{
    cout << "Hello World\n";
}
int func3(int h, int k)
{
    int s = h * k;
    return s;
}
void func4(int w, int o)
{
    if (w == o){
        cout << "a = b\n";
    }
}
void func5(int n, int u)
{
    if (n > u){
        cout << "a > b\n";
    }
}
void func6(int j, int i)
{
    if (j < i){
        cout << "a < b\n";
    }
}