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

    // �����
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

    wchar_t* cScreen = new wchar_t[nMapX * nMapY]; // ������ ��� ������ � �����
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // ����� ������
    SetConsoleActiveScreenBuffer(hConsole); // ����������� ������

    while (true) {
        // ���������� �������
        if (GetAsyncKeyState((unsigned short)VK_TAB) & 0x8000) { // ��� ������� �� TAB return 0
            delete[] cScreen; return 0;
        }
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // ���� ������
            nPlayerX--;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // ���� �������
            nPlayerX++;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // ���� ������
            nPlayerY--;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // ���� ����� 
            nPlayerY++;

            if (wMap.c_str()[nMapX * nPlayerX + nPlayerY] == '#') { // ���� ��� ������ ���������� �� # �� return 0
                delete[] cScreen; return 0;
            }
        }



    }

    return 0;
}