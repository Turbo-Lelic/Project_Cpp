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
	ptr = nullptr;

	cout << "������ - " << ptr << "\n";
	cout << "�������� - None" << "\n";
	// NULL == 0 && nullptr == 0 �� ����� nullptr

	return 0;
}