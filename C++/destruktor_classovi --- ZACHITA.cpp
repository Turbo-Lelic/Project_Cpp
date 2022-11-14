#include <iostream>
#include <string>
#include <locale>

using namespace std;

template <class T>
class Person {
public:
    Person(T name) {
        this->name = name;
        cout << "Вызвался конструктор " << this->name << "\n";
    }
    ~Person() {
        cout << "Вызвался деструктор " << name << "\n";
    }
private:
    T name;
};
int main(void) {
    setlocale(LC_ALL, "Russian");

    Person<string> alex("Alex");
    Person<string> *vova = new Person<string>("Vova");

    // вызывается деструктор для объекта sam
    delete vova;

    cout << "Конец Main()\n";

    return 0;
}