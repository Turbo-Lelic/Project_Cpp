#include <iostream>
#include <stdio.h>
#include <locale>
#include <cstring>
using namespace std;

void quicksort(char *items, int lens);
void qstr(char *items, int left, int right);

int k = 0;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    
    char d[] = "9876543210";
    
    quicksort(d, strlen(d));
    
    cout << d;
    
    return 1;
}
void quicksort(char *items, int lens){
    qstr(items, 0, lens - 1);
}
void qstr(char *items, int left, int right){
    char x, y;
    int i = left;
    int j = right;
    x = items[(left + right) / 2];

    cout << "i = " << i << "\t" << "j = " << j << "\t" << "x = " << x << "\n";
    
    do{
        cout << "\ndo =>> " << k++ << "\n";
        while ((items[i] < x) && (i < right)){
            i++;
        }
        while ((x < items[j]) && (j > left)){
            j--;
        } 
        if (i <= j){
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++, j--;
        }
        cout << "items[" << i << "] >> " << items[i] << "\n";
        cout << "items[" << j << "] >> " << items[j] << "\n";
        cout << "arr = " << items << "\n";
    } while (i <= j);
    if (left < j){
        qstr(items, left, j);
    }
    if (i < right){
        qstr(items, i, right);
    }
}