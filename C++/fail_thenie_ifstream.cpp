#include <iostream>
#include <fstream>

using namespace std;

signed main() {
	setlocale(LC_ALL, "Russian");

	ifstream fail;
	char chr;

	fail.open("fail.txt");
	if (!fail.is_open()) {
		cout << "fail.txt �� ��� ������";
	} else if (fail.is_open()) {
		cout << "fail.txt ��� ������\n";

		while (fail.get(chr)) {
			cout << chr;
		}
	}

	fail.close();
	return 0;
}