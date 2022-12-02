#include <iostream>
#include <fstream>
#include <string>

using namespace std;

signed main() {
	setlocale(LC_ALL, "Russian");

	ofstream fail;
	string str;

	fail.open("fail.txt"); // fail.open("fail.txt", ofstream::app);
	if (!fail.is_open()) {
		cout << "fail.txt не был открыт";
	} else if (fail.is_open()) {
		cin >> str;
		fail << str << endl;
	}
	fail.close();

	return 0;
}