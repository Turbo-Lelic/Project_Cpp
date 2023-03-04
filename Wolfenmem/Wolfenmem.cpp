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

wstring map;                    // Карта мирового пространства
int nScreenWidth = 120;			// Размер экрана консоли X (столбцы)
int nScreenHeight = 40;			// Размер экрана консоли Y (строки)
int nMapWidth = 16;				// Высота игрового поля
int nMapHeight = 16;	        // Ширина игрового поля
float fPlayerX = 8.0f;			// Стартовая позиция игрока X
float fPlayerY = 8.0f;          // Стартовая позиция игрока Y
float fPlayerA = 0.0f;			// Угол обзора
float fFOV = 3.0f / 4.0f;	    // Поле зрения
float fDepth = 16.0f;			// Максимальное расстояние зрения
float fSpeed = 3.0f;			// Скорость ходьбы

signed main() {
	setlocale(LC_ALL, "Russian");
	
	string str;
	cout << "Правила: Делаете уровень и проходите его или нет\n\n";
	cout << "Назначение клавишь:\nEsc - выйти\nShift - Ускорение ходьбы\nW - идти вперед\nA - поворот камеры налево\nS - идти назад\nD - повотор камеры направо\n\n";
	cout << "Хотите сделать свою карту?: Ответы: y/n "; cin >> str;

	if (str == "y") { // Создать карту мирового пространства # = настенный блок, . = пробел
		cout << "# = настенный блок, . = пробел\nЗадача: Скажите каков размер карты "; cin >> nMapWidth >> nMapHeight;
		cout << "Задача: нарисуйте карту\n";

		for (int nx = 0; nx < nMapWidth; nx++) {
			for (int ny = 0; ny < nMapWidth; ny++) {
				// доделать создание карты
			}
		}
	} else { // Создать карту мирового пространства по умолчанию # = настенный блок, . = пробел
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

	// экранный буфер
	wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight]; // Массив для записи в буфер
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
	SetConsoleActiveScreenBuffer(hConsole); // Отображение буфера
	DWORD dwBytesWritten = 0; // Дебаг

	auto tp1 = chrono::system_clock::now(); // Переменные для подсчета пройденного времени
	auto tp2 = chrono::system_clock::now(); // Тоже

	while (true) {
		// понадобится разница во времени для каждого кадра, чтобы вычислить модификацию
		// к скорости движения, чтобы обеспечить последовательное движение, как трассировка лучей
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		if (GetAsyncKeyState((unsigned short)VK_LSHIFT) & 0x8000 || GetAsyncKeyState((unsigned short)VK_RSHIFT) & 0x8000) { // Ускорение движения на LShift или RShift
			fSpeed = 5.5;
		} else { // Обычное движение
			fSpeed = 3.5;
		}

		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) { // Поворот против часовой стрелки
			fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) { // Поворот по часовой стрелке
			fPlayerA += (fSpeed * 0.75f) * fElapsedTime;
		}

		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) { // Движение вперед
			fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
			  
			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') { // Если столкнулись со стеной, то откатываем шаг
				fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) { // Движением назад
			fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
			fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;

			if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#') { // Если столкнулись со стеной, то откатываем шаг
				fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
				fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
			}
		}

		for (int x = 0; x < nScreenWidth; x++) {
			// Для каждого столбца вычислите угол проецируемого луча в пространство.
			float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

			// Найти расстояние до стены
			float fStepSize = 0.1f; // Размер приращения для raycasting, от уменьшения к увеличению									
			float fDistanceToWall = 0.0f; // разрешение

			bool bHitWall = false; // Установить, когда луч попадает в стену
			bool bBoundary = false; // Установить, когда луч попадает на границу между двумя стенами

			float fEyeX = sinf(fRayAngle); // Единичный вектор для луча в пространстве игрока X
			float fEyeY = cosf(fRayAngle); // Единичный вектор для луча в пространстве игрока Y

			// Постепенно отбрасывать луч от игрока вдоль угла луча, проверяя
			// пересечение с блоком
			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += fStepSize;
				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				// Проверить, выходит ли луч за пределы
				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true; // Просто установить расстояние на максимальную глубину
					fDistanceToWall = fDepth;
				} else {
					// Луч находится внутри, поэтому проверить надо, является ли ячейка луча стенным блоком
					if (map.c_str()[nTestX * nMapWidth + nTestY] == '#') {
						// луч ударился о стену
						bHitWall = true;
						// Чтобы выделить границы плитки, проведите луч из каждого угла
						// плитки игроку. Чем больше совпадает этот луч
						// к лучу рендеринга, тем ближе мы к тайлу
						// граница, которую мы заштрихуем, чтобы добавить деталей стенам
						vector<pair<float, float>> p;
						// Проверить каждый угол хит тайла, сохраняя расстояние от
						// игрока и вычисленное скалярное произведение двух лучей
						for (int tx = 0; tx < 2; tx++) {
							for (int ty = 0; ty < 2; ty++) {
								// Угол от угла
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx * vx + vy * vy);
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
								p.push_back(make_pair(d, dot));
							}
						}

						// Сортировка пар от ближайшей к самой дальней
						sort(p.begin(), p.end(), [](const pair<float, float> &left, const pair<float, float> &right) {return left.first < right.first;});

						// Первые два/три самые близкие (мы никогда не увидим все четыре)
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

			// Рассчитать расстояние до потолка и пола
			int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
			int nFloor = nScreenHeight - nCeiling;

			// Шейдерные стены на основе расстояния
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
				// Каждый ряд
				if (y <= nCeiling) {
					screen[y * nScreenWidth + x] = ' ';
				} else if (y > nCeiling && y <= nFloor) {
					screen[y * nScreenWidth + x] = nShade;
				} else {
					// Затенение пола в зависимости от расстояния
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

//		// Показать карту
//		for (int nx = 0; nx < nMapWidth; nx++)
//			for (int ny = 0; ny < nMapWidth; ny++) {
//				screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
//			}
//		screen[((int)fPlayerX + 1) * nScreenWidth + (int)fPlayerY] = 'o';

		// Рамка дисплея
		screen[nScreenWidth * nScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0, 0}, &dwBytesWritten);

		if (fPlayerX < 0.0) {
			return 0;
		}
	}
}