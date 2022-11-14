#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    bool x = true;
    float a, b, c = 0.0;
    
    cin >> x;
    cin >> a >> b >> c;

    float *ptr_a = &a;
    float *ptr_b = &b;
    float *ptr_c = &c;
    float min = *ptr_a;
    float max = *ptr_a;
    float sre = *ptr_a;

    // Находим min
    if (*ptr_b < min){
        min = *ptr_b;
    }
    if (*ptr_c < min){
        min = *ptr_c;
    }
 
    // Находим max
    if (*ptr_b > max){
        max = *ptr_b;
    }
    if (*ptr_c > max){
        max = *ptr_c;
    }
    
    // Находим sre
    if (*ptr_b < max && *ptr_b > min){
        sre = *ptr_b;
    }
    if (*ptr_c < max && *ptr_c > min){
        sre = *ptr_c;
    }

    if (x == true){
       min *= 2;
       max *= 2;
       sre *= 2;
       cout << min << " " << sre << " " << max;
    }                                             
    if (x == false){
        *ptr_a *= -1;
        *ptr_b *= -1;
        *ptr_c *= -1;
        cout << *ptr_a << " " << *ptr_b << " " << *ptr_c;
    }
    return 0;
}