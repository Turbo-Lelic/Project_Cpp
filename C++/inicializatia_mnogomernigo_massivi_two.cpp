#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int arr[4][2];

int main(void)
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            if (arr[i][j] - arr[i][0] < 0){
                arr[i][j] = 0;
            }
            else{
                cout << arr[i][j] - arr[i][0] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}