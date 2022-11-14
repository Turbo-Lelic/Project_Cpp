#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int x[4] = {1, 2, 3, 4};
    int y[4];
    int u[4];
    int z[4];
    z[0] = 1;
    z[1] = 2;
    z[2] = 3;
    z[3] = 4;

    cout << "\n";
    for (int i = 0; i < 4; i++){
        y[i] = i + 1;
        cout << "y[] = " << y[i];
        cout << "\n";
    }
    cout << "\n";
    for (int a = 0; a < 4; a++){
        cout << "x[] = " << x[a];
        cout << "\n";
    }
    cout << "\n";
    for (int b = 0; b < 4; b++){
        cout << "z[] = " << z[b];
        cout << "\n";
    }
    cout << "\n";
    for (int j = 0; j < 4; j++){
        cout << "u[]" << " = ";
        cin >> u[j];
    }
    cout << "\n";
    cout << "u[] = ";
    cout << "{ ";
    for (int l = 0; l < 4; l++){
        cout << u[l] << " ";
    }
    cout << "}";
    cout << "\n";
    return 0;
}