#include <iostream>
#include <string>
#include <locale>

using namespace std;

template <class T>
class Test {
public:
	Test(T x) {
		this->x = x;
	}
private:
	T x = 0;
};

template <class T1, class T2>
class MyClass {
public:
	MyClass(T1 value1, T2 value2) {
		this->value1 = value1;
		this->value2 = value2;
	}

	void Size_Value() {
		cout << "value1 = " << sizeof(value1) << "\n";
		cout << "value2 = " << sizeof(value2) << "\n";
	}
private:
	T1 value1 = 0;
	T2 value2 = 0;
};

int main(void) {
	setlocale(LC_ALL, "Russian");

	int n_t1 = 0;
	double n_t2 = 0.0;

	cin >> n_t1 >> n_t2;

	MyClass<int, double> myclass(n_t1, n_t2);

	myclass.Size_Value();

	return 0;
}