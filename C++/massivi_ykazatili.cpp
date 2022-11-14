#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    setConsoleCP(1251);
    setConsoleOutputCP(1251);

    const char *ptr_str[][2] = {
        "1", "Python",
        "2", "C++",
        "3", "C",
        "", ""
    };
    int flag = 0;
    char x[2];

    cout << "Введите имя пользователя: ";
    cin >> x;

    for(int i = 0; *ptr_str[i][0]; i++){
        if(!strcmp(ptr_str[i][0], x)){
            cout << ptr_str[i][1] << "\n";
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        cout << "Error\n";
    }
    return 0;
}