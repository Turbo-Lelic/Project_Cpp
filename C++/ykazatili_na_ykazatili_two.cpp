#include <iostream>
#include <stdio.h>
#include <locale>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int x = 10;
    int y = 20;
    int z = 30;
    int *ptr1_1;
    int *ptr1_2;
    int *ptr1_3;
    int **ptr2_1;
    int **ptr2_2;
    int **ptr2_3;

    ptr1_1 = &x;
    ptr2_1 = &ptr1_1;

    ptr1_2 = &y;
    ptr2_2 = &ptr1_2;

    ptr1_3 = &z;
    ptr2_3 = &ptr1_3;

    cout << "ptr2_1 + ptr2_2 + ptr2_3 = " << **ptr2_1 + **ptr2_2 + **ptr2_3 << "\n";
    cout << "ptr2_1 - ptr2_2 - ptr2_3 = " << **ptr2_1 - **ptr2_2 - **ptr2_3 << "\n"; 
    cout << "ptr2_1 * ptr2_2 * ptr2_3 = " << **ptr2_1 * **ptr2_2 * **ptr2_3 << "\n";
    cout << "ptr2_1 / ptr2_2 / ptr2_3 = " << **ptr2_1 / **ptr2_2 / **ptr2_3 << "\n";
    cout << "result+ = " << (**ptr2_1 + **ptr2_2 + **ptr2_3) + (**ptr2_1 - **ptr2_2 - **ptr2_3) + (**ptr2_1 * **ptr2_2 * **ptr2_3) + (**ptr2_1 / **ptr2_2 / **ptr2_3) << "\n";
    cout << "result- = " << (**ptr2_1 + **ptr2_2 + **ptr2_3) - (**ptr2_1 - **ptr2_2 - **ptr2_3) - (**ptr2_1 * **ptr2_2 * **ptr2_3) - (**ptr2_1 / **ptr2_2 / **ptr2_3) << "\n";
    cout << "result* = " << (**ptr2_1 + **ptr2_2 + **ptr2_3) * (**ptr2_1 - **ptr2_2 - **ptr2_3) * (**ptr2_1 * **ptr2_2 * **ptr2_3) * (**ptr2_1 / **ptr2_2 / **ptr2_3) << "\n";
    cout << "result/ = " << (**ptr2_1 + **ptr2_2 + **ptr2_3) / (**ptr2_1 - **ptr2_2 - **ptr2_3) / (**ptr2_1 * **ptr2_2 * **ptr2_3) / (**ptr2_1 / **ptr2_2 / **ptr2_3);

    return 0;
}