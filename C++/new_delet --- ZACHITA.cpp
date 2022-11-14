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

	return 0;
}