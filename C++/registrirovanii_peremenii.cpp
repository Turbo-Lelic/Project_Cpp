// register = описатель оптимизации по скорости обращения к переменным
 
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
 
    register int k = 0;
    register int sum = 0;
    register int p = 0;
    int h = 0;
    h = k + 1;
 
    while (1){
        cout << "count = " << run() << "\n";
        k++;
        sum = sum + k;
        p++;

        if (k > 20){
            break;
        }
    }
    return 0;
}
int run(){
    static int j = 0; 
    return j++;
}