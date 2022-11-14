#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void func_b();
void func_b_1(int d[5]);
int b[5];

int main(void)
{
    setlocale(LC_ALL, "Russian");

    func_b();
    func_b_1(b);

    cout << "\n";

    func_b();
    func_b_1(b);

    cout << "\n";

    func_b();
    func_b_1(b);

    cout << "\n";

    return 0;
}
void func_b()
{
    for (int j = 0; j < 5; j++){
        cout << "Введите b[" << j << "] = ";
        cin >> b[j];
    }
}
void func_b_1(int d[5])
{
    for (int l = 0; l < 5; l++){
        cout << d[l];
    }
}