#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    char x = '!';

    printf("Hello World!\n");
    cout << "Hello World!\n";   
    cout << "Hello World" << x << "\n";
    
    return 0;
}