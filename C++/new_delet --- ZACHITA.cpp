#include <iostream>
#include <locale>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");

	int *ptr = new int;
	*ptr = 10;

	cout << "������ - " << ptr << "\n";
	cout << "�������� - " << *ptr << "\n";

	delete ptr;

	return 0;
}