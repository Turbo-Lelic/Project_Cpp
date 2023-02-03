#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

#define NONE 0

class Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\nНе учусь...\n";
	}
	void SetName(string name) {
		this->name = name;
	}
	void GetName() {
		cout << "Мое имя: " << name << endl;
	}
private:
	string name = "NONE";
};

class Student:public Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\nУчусь...\n";
	}
	void SetGroup(int group) {
		this->group = group;
	}
	void GetGroup() {
		cout << group << " группа" << endl;
	}
private:
	int group = NONE;
};

class Professor:public Human {
public:
	void learn() {
		cout << typeid(*this).name() << "\nЯ не учусь я преподаю...\n";
	}
	void SetSubject(string subject) {
		this->subject = subject;
	}
	void GetSubject() {
		cout << "Преподаю предмет: " << subject << endl;
	}
private:
	string subject = "NONE";
};

signed main() {
	setlocale(LC_ALL, "Russian");

	Human H; Student S; Professor P;
	H.learn(); H.SetName("Леха"); H.GetName();
	cout << endl;
	S.learn(); S.SetName("Глеб"); S.SetGroup(1); S.GetName(); S.GetGroup();
	cout << endl;
	P.learn(); P.SetName("Проф"); P.SetSubject("Информатика"); P.GetName(); P.GetSubject();

	return 0;	
}