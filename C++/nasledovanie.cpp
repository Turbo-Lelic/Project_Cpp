#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#define NONE 0

class Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\n�� �����...\n";
	}
	void SetName(string name) {
		this->name = name;
	}
	void GetName() {
		cout << "��� ���: " << name << endl;
	}
private:
	string name = "NONE";
};

class Student:public Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\n�����...\n";
	}
	void SetGroup(int group) {
		this->group = group;
	}
	void GetGroup() {
		cout << group << " ������" << endl;
	}
private:
	int group = NONE;
};

class Professor:public Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\n� �� ����� � ��������...\n";
	}
	void SetSubject(string subject) {
		this->subject = subject;
	}
	void GetSubject() {
		cout << "�������� �������: " << subject << endl;
	}
private:
	string subject = "NONE";
};

signed main() {
	setlocale(LC_ALL, "Russian");

	Human H; Student S; Professor P;
	H.learn(); H.SetName("����"); H.GetName();
	cout << endl;
	S.learn(); S.SetName("����"); S.SetGroup(1); S.GetName(); S.GetGroup();
	cout << endl;
	P.learn(); P.SetName("����"); P.SetSubject("�����������"); P.GetName(); P.GetSubject();

	return 0;	
}