#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

void func();
void func1();
void func2();
void func3();
void func4();
float x, y = 0;
char z = '0';

int main(void)
{
    setlocale(LC_ALL, "Russian");

    func();
    func1();
    func2();
    func3();
    func4();

    return 0;
}
void func()
{
    cout << "Max действий: -, +, *, /\n";
    cout << "Сохрание действие: ";
    cin >> z;
    cout << "\n";
    cout << "Max чисел: 2\n";
    cout << "Сохраните значение в x: ";
    cin >> x;
    cout << "Сохраните значение в y: ";
    cin >> y;
}
void func1()
{
    if (z == '-'){
        cout << "\nОтвет: " << x - y << "\n";
    }
}
void func2()
{
    if (z == '+'){
        cout << "\nОтвет: " << x + y << "\n";
    }
}
void func3()
{
    if (z == '*'){
        cout << "\nОтвет: " << x * y << "\n";
    }
}
void func4()
{
    if (z == '/'){
        cout << "\nОтвет: " << x / y << "\n";
    }
}