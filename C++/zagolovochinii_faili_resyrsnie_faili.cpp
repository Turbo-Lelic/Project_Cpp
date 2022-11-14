#include "main.h"

int main(void)
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCp(1251);

    wh();

    if (DEBUG){
        wh2();
    }

    #ifdef DEBUG2
        wh3();
    #endif

    return 0;
}