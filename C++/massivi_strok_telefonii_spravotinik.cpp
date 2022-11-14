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

    char str[80];
    char num[10][80] = {
    "Александр", "+7 905 878 34 10",
    "Григорий", "+7 905 890 11 11", 
    "Оксана", "+7 905 878 34 11", 
    "Михаил", "+7 905 890 73 65",
    "Павел", "+7 905 878 35 60", 
    "Роман", "+7 905 878 89 10", 
    "Семен", "+7 905 890 34 10",
    "Глеб", "+7 905 890 00 00",
    "Джон", "+7 905 890 22 22",
    "Лиза", "+7 905 890 33 33",
};

    cout << "Введите имя человека у которого хотите узнать номер: ";
    cin >> str;

    for (int j = 0; j < 10; j += 2){
        if (strcmp(str, num[j]) != 0){
            cout << "Телефон: " << num[j + 1] << "\n";
            break;
        }
    }
    if (j == 10) {
        cout << "Такого человека нет у вас в контактах: ";
    }    
    return 0;
}