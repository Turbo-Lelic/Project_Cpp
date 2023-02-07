#include <iostream>

using namespace std;

class A {
public:
    A() { //����������� �� ��������� ������� ���������� ��� �������� ������� ������ A � B
        msg = "msg";
    }
    A(string msg) { //����������� 1
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
    B():A("GG") { //��� :A("GG") ���� ������ ��� �������� ������� ������ B �������� ����������� �� ��������� A ����� B �� � ����� ������� �� �������� ����������� 1 � ������ A � ����� ����������� �� ��������� B

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