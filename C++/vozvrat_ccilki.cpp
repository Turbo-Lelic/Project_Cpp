#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int &f();
int &f1(int i);

int p1 = 500;
int m[] = {1, 2, 3, 4, 5};

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    // Было

    cout << "p1 = " << p1 << "\n";
    
    f() = 30;

    // Стало

    cout << "p1 = " << p1 << "\n";

    int s = f();

    // Стало

    cout << "s = " << s << "\n";

    // Было

    for (int i = 0; i < 5; i++){ 
        cout << m[i] << " ";
    }
    cout << "\n";

    f1(2) = 100;

    // Стало

    for (int i = 0; i < 5; i++){
        cout << m[i] << " ";
    }

    return 0;
}
int &f(){
    return p1;
}
int &f1(int i){
    return m[i];
}