#include <iostream>
#include <locale>

using namespace std;

class MyClass {
private:
	// ��������� ��� ��������� ������������ ������
	int *data;
	// ������ �������
	int size;
public:
	// ���� � ����������� �������� int �������� �� 
	// ���������� ����������� ����������� ������ ������� � ����� �������� ������� � ������������ ������ ������� size
	MyClass(int size) {
		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++) {
			data[i] = i;
		}
		cout << "�������� ����������� - " << this << "\n";
	};

	// ���� � ����������� �������� ������ �� ������ MyClass ��
	// ���������� ����������� ����������� ������ �� ������ MyClass � ����� � size ����������� �������� ������� other
	// ����� � ��������� ����������� ������ � ������������ ������ �������� size other
	MyClass(const MyClass &other) {
		this->size = other.size;
		this->data = new int [size];

		for (int i = 0; i < size; i++) {
			this->data[i] = other.data[i];
		}
		cout << "�������� ����������� ����������� - " << this << "\n";
	};

	// ��� ������ ����������� ��������� ������������ ������ ������� �� �������� ���������� ��� ���� ����� ������� ������ size ���������
	~MyClass() {
		cout << "�������� ���������� - " << this << "\n";
		// ��������� ������������ ������ ������� �� �������� 
		delete[] data;
		// ��������� ������ �� ������
		data = nullptr;
	};
};

// ��� ������� ��� �����
void func1(MyClass object) {
	cout << "��������� ������� func\n";
}

MyClass func2() {
	MyClass n(2);
	cout << "��������� ������� func2\n";

	return n;
}

int main(void) {
	setlocale(LC_ALL, "Russian");

	// ������1 ������� ��������� ������ �������
	MyClass n1(10);
	// ������2 ������� �������� �������� �������1 �� � ����� ������� ������ ������
	MyClass n2(n1);
	// ��� ������� ��� �����
	func1(n1);
	func2();

	return 0;
}