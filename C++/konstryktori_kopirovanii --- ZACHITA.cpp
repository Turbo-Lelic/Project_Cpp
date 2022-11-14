#include <iostream>
#include <locale>

using namespace std;

class MyClass {
private:
	// указатель для выделения динамической памяти
	int *data;
	// размер массива
	int size;
public:
	// если в конструктор подается int значение то 
	// вызывается конструктор принимающий размер массива и далее создания массива в динамической паняти размера size
	MyClass(int size) {
		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++) {
			data[i] = i;
		}
		cout << "Вызвался конструктор - " << this << "\n";
	};

	// если в конструктор подается ссылка на объект MyClass то
	// вызывается конструктор принимающий ссылку на объект MyClass и далее в size сохраняется значение объекта other
	// далее в указатель сохраняется массив в динамическую память размером size other
	MyClass(const MyClass &other) {
		this->size = other.size;
		this->data = new int [size];

		for (int i = 0; i < size; i++) {
			this->data[i] = other.data[i];
		}
		cout << "Вызвался конструктор копирования - " << this << "\n";
	};

	// при вызове деструктора очищается динамическая память которую мы занимали указателям для того чтобы создать массив size элементов
	~MyClass() {
		cout << "Вызвался деструктор - " << this << "\n";
		// очищается динамическая память которую мы занимали 
		delete[] data;
		// очищается ссылка на память
		data = nullptr;
	};
};

// две функции для теста
void func1(MyClass object) {
	cout << "Вызвалась функция func\n";
}

MyClass func2() {
	MyClass n(2);
	cout << "Вызвалась функция func2\n";

	return n;
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	// объект1 который принимает размер массива
	MyClass n1(10);
	// объект2 который копирует значение объекта1 но у этого объекта другая ссылка
	MyClass n2(n1);
	// две функции для теста
	func1(n1);
	func2();

	return 0;
}