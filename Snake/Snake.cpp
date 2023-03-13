#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <locale>
#include <stdio.h>
#include <chrono>

using namespace std;

wstring wMap;            // Карта Поля
int nMapX = 16;          // Размер поля X (столбцы)
int nMapY = 16;          // Размер поля Y (строки)
int nPlayerX = 8;        // Стартовая позиция игрока X (столбцы)
int nPlayerY = 8;        // Стартовая позиция игрока Y (строки)

signed main(void) {
    setlocale(LC_ALL, "Russian");

    // Карта
    wMap += L"################";
    wMap += L"#              #";
    wMap += L"#          #   #";
    wMap += L"#   #          #";
    wMap += L"#      ##  #   #";
    wMap += L"#      ##      #";
    wMap += L"#              #";
    wMap += L"#      #       #";
    wMap += L"#          #   #";
    wMap += L"#    #         #";
    wMap += L"#              #";
    wMap += L"#  ##      #   #";
    wMap += L"#  ##          #";
    wMap += L"#     #  #     #";
    wMap += L"#              #";
    wMap += L"################";

    wchar_t* cScreen = new wchar_t[nMapX * nMapY]; // Массив для записи в буфер
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
    SetConsoleActiveScreenBuffer(hConsole); // Отображение буфера

    while (true) {
        // считывание клавишь
        if (GetAsyncKeyState((unsigned short)VK_TAB) & 0x8000) { // При нажатии на TAB return 0
            delete[] cScreen; return 0;
        }
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // Идти налево
            nPlayerX--;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // Идти направо
            nPlayerX++;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // Идти вперед
            nPlayerY--;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // Идти назад 
            nPlayerY++;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }



    }

    return 0;
}