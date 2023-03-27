// ������� �������� ������ ��� ����� ������� � ������ � ������� ��������� �����
// ������� ��� ���������� P � ������� == nPlayerX + (nPlayerY * (nMapX + 1))
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <locale>
#include <stdio.h>
#include <chrono>

using namespace std;

wstring wMap;            // ����� ����
int nMapX = 16;          // ������ ���� X (�������)
int nMapY = 16;          // ������ ���� Y (������)
int nPlayerX = 8;        // ��������� ������� ������ X (�������)
int nPlayerY = 8;        // ��������� ������� ������ Y (������)

signed main(void) {
    setlocale(LC_ALL, "Russian"); 
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    // �����
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

    DWORD dwDebug = 0; // �����	
    wchar_t *cScreen = new wchar_t[nMapX * nMapY]; // ������ ��� ������ � �����
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // ����� ������
    SetConsoleActiveScreenBuffer(hConsole); // ����������� ������

    while (true) {
        // ���������� �������
        if (GetAsyncKeyState((unsigned short)VK_TAB) & 0x8000) { // ��� ������� �� TAB return 0
            delete[] cScreen; return 0;
        }
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // ���� ������
            nPlayerX--;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // ���� �������
            nPlayerX++;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // ���� ������
            nPlayerY--;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // ���� ����� 
            nPlayerY++;

            if (wMap.c_str()[nPlayerX + (nPlayerY * (nMapX + 1))] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }

        // ��������
        for (int x = 0; x < nMapX; x++) {
            for (int y = 0; y < nMapY; y++) {
                for (int nx = 0; nx < nMapX; nx++) {
                    for (int ny = 0; ny < nMapY; ny++) {    
                        cScreen[ny * nx] = wMap[ny * nx];
                    }
                    cScreen[nPlayerX + (nPlayerY * (nMapX + 1))] = 'P';
                }
                // ����� 
                cScreen[nMapX * nMapY - 1] = '\0';
                WriteConsoleOutputCharacter(hConsole, cScreen, nMapX * nMapY, {0, 0}, &dwDebug);
            }
        }
    }
}