#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

const int x = 4;
const int y = 2;
int add[x][y];
int arr[x][y] = {
    1, 1,
    2, 3,
    6, 7,
    8, 7
};
int aff[][y] = {
    1, 2,
    3, 4,
    5, 6,
    7, 8,
    9, 10
};
int main(void)
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int l = 0; l < 4; l++){
        for (int p = 0; p < 2; p++){
            cin >> add[l][p];
        }
        cout << "\n";
    }
    for (int l = 0; l < 4; l++){
        for (int p = 0; p < 2; p++){
            cout << add[l][p] << " ";
        }
        cout << "\n";
    }
    return 0;
}