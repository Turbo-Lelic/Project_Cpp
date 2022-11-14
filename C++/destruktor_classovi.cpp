#include <iostream>
#include <string>
#include <locale>

using namespace std;

template <class T>
class Person {
public:
    Person(T name) {
        this->name = name;
        cout << "�������� ����������� " << this->name << "\n";
    }
    ~Person() {
        cout << "�������� ���������� " << name << "\n";
    }
private:
    T name;
};
int main(void) {
    setlocale(LC_ALL, "Russian");

    Person<string> alex("Alex");
    Person<string> *vova = new Person<string>("Vova");

    // ���������� ���������� ��� ������� sam
    delete vova;

    cout << "����� Main()\n";

    return 0;
}