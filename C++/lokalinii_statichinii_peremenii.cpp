#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int run();

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    int k = 0;

    while (1){
        cout << "count = " << run() << "\n";
        k++;
        if (k > 20){
            break;
        }
    }
    return 0;
}
int run(){
    static int j = -1;
    j++;    
    return j;
}