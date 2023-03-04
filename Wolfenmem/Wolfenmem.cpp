#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <stdio.h>
#include <Windows.h>
#include <locale>
#include <string>

using namespace std;

wstring map;                    // ����� �������� ������������
int nScreenWidth = 120;			// ������ ������ ������� X (�������)
int nScreenHeight = 40;			// ������ ������ ������� Y (������)
int nMapWidth = 16;				// ������ �������� ����
int nMapHeight = 16;	        // ������ �������� ����
float fPlayerX = 8.0f;			// ��������� ������� ������ X
float fPlayerY = 8.0f;          // ��������� ������� ������ Y
float fPlayerA = 0.0f;			// ���� ������
float fFOV = 3.0f / 4.0f;	    // ���� ������
float fDepth = 16.0f;			// ������������ ���������� ������
float fSpeed = 3.0f;			// �������� ������

signed main() {
	setlocale(LC_ALL, "Russian");
	
	string str;
	cout << "�������: ������� ������� � ��������� ��� ��� ���\n\n";
	cout << "���������� �������:\nEsc - �����\nShift - ��������� ������\nW - ���� ������\nA - ������� ������ ������\nS - ���� �����\nD - ������� ������ �������\n\n";
	cout << "������ ������� ���� �����?: ������: y/n "; cin >> str;

	if (str == "y") { // ������� ����� �������� ������������ # = ��������� ����, . = ������
		cout << "# = ��������� ����, . = ������\n������: ������� ����� ������ ����� "; cin >> nMapWidth >> nMapHeight;
		cout << "������: ��������� �����\n";

		for (int nx = 0; nx < nMapWidth; nx++) {
			for (int ny = 0; ny < nMapWidth; ny++) {
				// �������� �������� �����
			}
		}
	} else { // ������� ����� �������� ������������ �� ��������� # = ��������� ����, . = ������
		map += L"##########.#####";
		map += L"#......#.#.....#";
		map += L"#......#.####..#";
		map += L"#......#.#.....#";
		map += L"#...#..#.#.....#";
		map += L"#......#.#.....#";
		map += L"#..#...#.#.##..#";
		map += L"#......#.#.....#";
		map += L"#...#....#.....#";
		map += L"#......#.#.....#";
		map += L"########.#.....#";
		map += L"#......#.#.....#";
		map += L"#..##..#.####.##";
		map += L"#..##..........#";
		map += L"#......#.#######";
		map += L"################";
	}

	// �������� �����
	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight]; // ������ ��� ������ � �����
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // ����� ������
	SetConsoleActiveScreenBuffer(hConsole); // ����������� ������
	DWORD dwBytesWritten = 0; // �����

	auto tp1 = chrono::system_clock::now(); // ���������� ��� �������� ����������� �������
	auto tp2 = chrono::system_clock::now(); // ����

	while (true) {
		// ����������� ������� �� ������� ��� ������� �����, ����� ��������� �����������
		// � �������� ��������, ����� ���������� ���������������� ��������, ��� ����������� �����
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)VK_LSHIFT) & 0x8000 || GetAsyncKeyState((unsigned short)VK_RSHIFT) & 0x8000) { // ��������� �������� �� LShift ��� RShift
			fSpeed = 5.5;
		} else { // ������� ��������
			fSpeed = 3.5;
		}

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // ������� ������ ������� �������
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // ������� �� ������� �������
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // �������� ������
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
			  
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // ��������� �����
			fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;

			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') { // ���� ����������� �� ������, �� ���������� ���
				fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		for (int x = 0; x < nScreenWidth; x++) {
			// ��� ������� ������� ��������� ���� ������������� ���� � ������������.
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			// ����� ���������� �� �����
			float fStepSize = 0.1f; // ������ ���������� ��� raycasting, �� ���������� � ����������									
			float fDistanceToWall = 0.0f; // ����������

			bool bHitWall = false; // ����������, ����� ��� �������� � �����
			bool bBoundary = false; // ����������, ����� ��� �������� �� ������� ����� ����� �������

			float fEyeX = sinf(fRayAngle); // ��������� ������ ��� ���� � ������������ ������ X
			float fEyeY = cosf(fRayAngle); // ��������� ������ ��� ���� � ������������ ������ Y

			// ���������� ����������� ��� �� ������ ����� ���� ����, ��������
			// ����������� � ������
			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += fStepSize;
				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// ���������, ������� �� ��� �� �������
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true; // ������ ���������� ���������� �� ������������ �������
					fDistanceToWall = fDepth;
				} else {
					// ��� ��������� ������, ������� ��������� ����, �������� �� ������ ���� ������� ������
					if (map.c_str()[nTestX * nMapWidth + nTestY] == '#') {
						// ��� �������� � �����
						bHitWall = true;
						// ����� �������� ������� ������, ��������� ��� �� ������� ����
						// ������ ������. ��� ������ ��������� ���� ���
						// � ���� ����������, ��� ����� �� � �����
						// �������, ������� �� ����������, ����� �������� ������� ������
						vector<pair<float, float>> p;
						// ��������� ������ ���� ��� �����, �������� ���������� ��
						// ������ � ����������� ��������� ������������ ���� �����
						for (int tx = 0; tx < 2; tx++) {
							for (int ty = 0; ty < 2; ty++) {
								// ���� �� ����
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx * vx + vy * vy);
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
								p.push_back(make_pair(d, dot));
							}
						}

						// ���������� ��� �� ��������� � ����� �������
						sort(p.begin(), p.end(), [](const pair<float, float> &left, const pair<float, float> &right) {return left.first < right.first;});

						// ������ ���/��� ����� ������� (�� ������� �� ������ ��� ������)
						float fBound = 0.01f;

						if (acos(p.at(0).second) < fBound) {
							bBoundary = true;
						}
						if (acos(p.at(1).second) < fBound) {
							bBoundary = true;
						}
						if (acos(p.at(2).second) < fBound) {
							bBoundary = true;
						}
					}
				}
			}

			// ���������� ���������� �� ������� � ����
			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			// ��������� ����� �� ������ ����������
			short nShade = ' ';

			if (fDistanceToWall <= fDepth / 4.0f) {
				nShade = 0x2588;
			} else if (fDistanceToWall < fDepth / 3.0f) {
				nShade = 0x2593;
			} else if (fDistanceToWall < fDepth / 2.0f) {
				nShade = 0x2592;
			} else if (fDistanceToWall < fDepth) {
				nShade = 0x2591;
			} else {
				nShade = ' ';
			}
			if (bBoundary) {
				nShade = ' ';
			}

			for (int y = 0; y < nScreenHeight; y++) {
				// ������ ���
				if (y <= nCeiling) {
					screen[y * nScreenWidth + x] = ' ';
				} else if (y > nCeiling && y <= nFloor) {
					screen[y * nScreenWidth + x] = nShade;
				} else {
					// ��������� ���� � ����������� �� ����������
					float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));

					if (b < 0.6) {
						nShade = '#';
					} else if (b < 0.7) {
						nShade = 'x';
					} else if (b < 0.8) {
						nShade = '-';
					} else if (b < 0.9) {
						nShade = '.';
					} else {
						nShade = ' ';
					}
					screen[y * nScreenWidth + x] = nShade;
				}
			}
		}

		swprintf_s(screen, 50, L"X=%3.2f, Y=%3.2f, A=%3.2f, S=%3.2f, FPS=%3.2f ", fPlayerX, fPlayerY, fPlayerA, fSpeed, 1.0f / fElapsedTime);

//		// �������� �����
//		for (int nx = 0; nx < nMapWidth; nx++)
//			for (int ny = 0; ny < nMapWidth; ny++) {
//				screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
//			}
//		screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'o';

		// ����� �������
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0, 0}, &dwBytesWritten);

		if (fPlayerX < 0.0) {
			return 0;
		}
	}
}