#include <iostream>
#include <locale>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");

	int *ptr = new int;
	*ptr = 10;

	cout << "—сылка - " << ptr << "\n";
	cout << "«начение - " << *ptr << "\n";

	delete ptr;
	ptr = nullptr;

	cout << "—сылка - " << ptr << "\n";
	cout << "«начение - None" << "\n";
	// NULL == 0 && nullptr == 0 но лучше nullptr

	return 0;
}