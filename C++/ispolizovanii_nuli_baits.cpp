#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

void main1(void);
void main2(void);
void main3(void);
void main4(void);
void main5(void);
void main6(void);
char str[] = "This is first programm";
int l = 0;
int main(void)
{
    setlocale(LC_ALL, "Russian");

    main1();
    main2();
    main3();
    main4();
    main5();
    main6();

    return 0;
}
void main1(void)
{
    for (int i = 0; str[i] != '\0'; i++){
        cout << str[i] << "\n";
    }
}
void main2(void)
{
    for (int j = 0; str[j]; j++){
        cout << str[j] << "\n";
    }
}
void main3(void)
{
    for (int j = 0; str[j] > '\0'; j++){
        cout << str[j] << "\n";
    }
}
void main4(void)
{
    while (str[l] != '\0'){
        cout << str[l] << "\n";
        l++;
    }
}
void main5(void)
{
    while (str[l]){
        cout << str[l] << "\n";
        l++;
    }
}
void main6(void)
{
    while (str[l] > '\0'){
        cout << str[l] << "\n";
        l++;
    }
}