#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    int x = 10;
    int y = 20;
    int z = 30;

    int *x_x = &x;
    int *y_y = &y;
    int *z_z = &z;

    int d = *x_x;
    int b = *y_y;
    int db = *z_z;

    char v = '!';
    char c = '?';
    char u = '.';

    char *v_v = &v;
    char *c_c = &c;
    char *u_u = &u;

    char i = *v_v;
    char j = *c_c;
    char l = *u_u;

    cout << d << " " << i << "\n" << b << " " << j << "\n" << db << " " << l << "\n";

    return 0;
}