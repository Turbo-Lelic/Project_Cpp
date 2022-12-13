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
		cout << "fail.txt не был открыт\n";
		return 0;
	} else if (fs.is_open()) {
		cout << "fail.txt был открыт\n¬ведите 1 чтобы записать данные в fail.txt\n¬ведите 2 чтобы считать все данные из fail.txt\n";
		cin >> value;

		if (value == 1) {
			SetConsoleCP(1251);
			cout << "¬ведите сообщение: "; cin >> buff; fs << buff << endl;
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