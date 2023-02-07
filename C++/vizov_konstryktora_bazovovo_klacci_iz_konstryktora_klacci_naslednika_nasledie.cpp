#include <iostream>

using namespace std;

class A {
public:
    A() { //конструктор по умолчанию который вызывается при создании объекта класса A и B
        msg = "msg";
    }
    A(string msg) { //конструктор 1
        this->msg = msg;
    }
    void PrintMsg() {
        cout << msg << endl;
    }
private:
    string msg = "";
};

class B : public A {
public:
    B():A("GG") { //без :A("GG") этой записи при создании объекта класса B вызвался конструктор по умолчанию A потом B но с такой записью мы вызываем конструктор 1 у класса A а потом конструктор по умолчанию B

    }
};

class C final : public B {
public:
    C():B() {

    }
};

signed main() {
    C c;
    c.PrintMsg();

    return 0;
}