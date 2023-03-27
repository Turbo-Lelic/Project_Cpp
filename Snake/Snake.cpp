// Главная проблема сейчас это найти елемент в строке в котором находится игрок
// Формула для нахождения P в массиве == nPlayerX + (nPlayerY * (nMapX + 1))
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
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    // Карта
    wMap += L"################";
    wMap += L"#              #";
    wMap += L"#              #";
    wMap += L"#        ##    #";
    wMap += L"#  ##          #";
    wMap += L"#              #";
    wMap += L"#   ##         #";
    wMap += L"#   ##    #    #";
    wMap += L"#              #";
    wMap += L"#  #           #";
    wMap += L"#         #    #";
    wMap += L"#              #";
    wMap += L"#   #          #";
    wMap += L"#        ##    #";
    wMap += L"#              #";
    wMap += L"################";

    DWORD dwDebug = 0; // Дебаг	
    wchar_t *cScreen = new wchar_t[nMapX * nMapY]; // Массив для записи в буфер
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
    SetConsoleActiveScreenBuffer(hConsole); // Отображение буфера

    while (true) {
        // считывание клавишь
        if (GetAsyncKeyState((unsigned short)VK_TAB) & 0x8000) { // При нажатии на TAB return 0
            delete[] cScreen; return 0;
        }
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // Идти налево
            nPlayerX--;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // Идти направо
            nPlayerX++;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // Идти вперед
            nPlayerY--;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // Идти назад 
            nPlayerY++;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // Если при ходьбе наткнулись на # то return 0
                delete[] cScreen; return 0;
            }
        }

        // Доделать
        for (int x = 0; x < nMapX; x++) {
            for (int y = 0; y < nMapY; y++) {
                for (int nx = 0; nx < nMapX; nx++) {
                    for (int ny = 0; ny < nMapY; ny++) {    
                        cScreen[ny * nx] = wMap[ny * nx];
                    }
                    cScreen[nPlayerX + (nPlayerY * (nMapX + 1))] = 'P';
                }
                // Рамка 
                cScreen[nMapX * nMapY - 1] = '\0';
                WriteConsoleOutputCharacter(hConsole, cScreen, nMapX * nMapY, {0, 0}, &dwDebug);
            }
        }
    }
}