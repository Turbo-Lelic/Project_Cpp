#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

signed main() {
	setlocale(LC_ALL, "Russian"); 

	int value = 0; string buff;

	fstream fs;
	fs.open("file.txt", fstream::in | fstream::out | fstream::app);

	if (!fs.is_open()) {
		cout << "fail.txt �� ��� ������\n";
		return 0;
	} else if (fs.is_open()) {
		cout << "fail.txt ��� ������\n������� 1 ����� �������� ������ � fail.txt\n������� 2 ����� ������� ��� ������ �� fail.txt\n";
		cin >> value;

		if (value == 1) {
			SetConsoleCP(1251);
			cout << "������� ���������: "; cin >> buff; fs << buff << endl;
			SetConsoleCP(866);
		} else if (value == 2) {
			while (!fs.eof()) {
				buff = ""; fs >> buff; cout << buff << endl;
			}
		} else {
			cout << "Error\n";
		}
	}
	
	fs.close();
	return 0;
}