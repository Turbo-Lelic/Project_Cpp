#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

class Point{    
private:
    int z = 0;

public:
    int x = 0;
    int y = 0;

    void print(){
        cout << "x = " << x << "\n" << "y = " << y << "\n" << "z = " << z << "\n";
    }
};

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    Point first;

    Point *ptr_first = &first;

    ptr_first->print();

    return 0;
}