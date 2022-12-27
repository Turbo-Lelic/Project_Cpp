#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
	MyClass(string str);
	void Print();
private:
	string str;
};

MyClass::MyClass(string str) {
	this->str = str;
}
void MyClass::Print() {
	cout << str;
}

signed main() {
	MyClass object("hello");
	object.Print();

	return 0;
}