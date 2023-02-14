#include <iostream>
#include <locale>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int x = 0;
    int y = 0;
    int num = 0;
    int *ptrx = &x;
    int *ptry = &y;

    *ptrx = 35;
    *ptry = 30;

    (*ptrx)++;
    cout << "ptrx = " << x << "\n";

    (*ptrx)--;
    cout << "ptrx = " << x << "\n";

    (*ptrx)-=2;
    cout << "ptrx = " << x << "\n";

    (*ptrx)+=2;
    cout << "ptrx = " << x << "\n\n";

    (*ptry)++;
    cout << "ptry = " << y << "\n";

    (*ptry)--;
    cout << "ptry = " << y << "\n";

    (*ptry)-=2;
    cout << "ptry = " << y << "\n";

    (*ptry)+=2;
    cout << "ptry = " << y << "\n\n";

    num = *ptrx + *ptry;
    cout << "ptrx + ptry = " << num << "\n";

    num = *ptrx - *ptry;
    cout << "ptrx - ptry = " << num << "\n";

    num = *ptrx * *ptry;
    cout << "ptrx * ptry = " << num << "\n";

    num = *ptrx / *ptry;
    cout << "ptrx - ptry = " << num;

    return 0;
}