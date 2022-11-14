#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int x = 0;
    int y = 0;
    int z = 0;
    int o = 0;
    int p = 0;
    int k = 0;

    cout << "Настройте значение x: ";
    cin >> x;
    cout << "Настройте значение y: ";
    cin >> y;
    cout << "Настройте значение z: ";
    cin >> z;
    cout << "Настройте значение o: ";
    cin >> o;
    cout << "Настройте значение p: ";
    cin >> p;
    cout << "Настройте значение k: ";
    cin >> k;

    if (x == 10 || x == 20) cout << "x = yes\n";

    else cout << "x = no\n";

    if (y == 10 || y == 20) cout << "y = yes\n";

    else cout << "y = no\n";

    if (z == 10 || z == 20) cout << "z = yes\n";
 
    else cout << "z = no\n"; 

    if (o == 10 || o == 20){
        cout << "o = yes\n";
    }
    else{
        cout << "o = no\n";
    }
    if (p == 10 || p == 20){
        cout << "p = yes\n";
    }
    else{
        cout << "p = no\n";
    }
    if (k == 10 || k == 20){
        cout << "k = yes\n";
    }
    else{
        cout << "k = no\n";
    }
    return 0;
}