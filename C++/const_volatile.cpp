// const = неизменяемая переменная
// volatile = если переменная не инициализированна то компилятор ее грохнит для оптимизации если прописать volatile то нет

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <locale>
using namespace std;

int constt(const int *v);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    // const

    const int x = 5;
    int mas1[x] = {0, 0, 0, 0, 0};
    int flag = 0;
    int res, s;

    res = constt(&s);

    for (int i = 0; i < x; i++){
        flag++;
        mas1[i] = flag;
    }
    for (int j = 0; j < x; j++){
        cout << mas1[j];
    }

    // volatile

    volatile int time_1;
    int h = time_1;

    return 0;
}

// const func

int constt(const int *v){
    return -*v;
}