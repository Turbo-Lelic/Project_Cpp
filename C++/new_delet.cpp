#include <iostream>
#include <locale>

using namespace std;

signed main() {
	setlocale(LC_ALL, "Russian");

	int *ptr_10 = new int;
	int *ptr_arr = new int[5];

	*ptr_10 = 10;
	for (int i = 0; i < 5; i++) {
		ptr_arr[i] = i + 1;
		cout << "&ptr_arr[" << i << "] = " << &ptr_arr[i] << endl;
		cout << "*ptr_arr[" << i << "] = " << ptr_arr[i] << endl;
	}
	cout << "&ptr_10 = " << &ptr_10 << endl;
	cout << "*ptr_10 = " << *ptr_10 << endl;

	delete ptr_10; ptr_10 = nullptr;
	delete[0] ptr_arr; ptr_arr = nullptr;

	return 0;
}