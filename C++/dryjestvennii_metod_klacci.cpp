#include <iostream>

using namespace std;

enum Enum {
	RED = 0,
	GREEN,
	YELLOW,
	GREY
};

class Apple;

class Human {
public:
	void TakeApple(Apple &apple);
};

class Apple {
public:
	Apple(int weight, Enum color) {
		this->weight = weight; this->color = color;
	}
	Apple(int weight) {
		this->weight = weight;
	}
	Apple(Enum color) {
		this->color = color;
	}
	Apple() {}
private:
	int weight = 0;
	Enum color = RED;

	friend void Human::TakeApple(Apple &apple);
};

signed main() {
	Apple apple(150, GREEN);
	Human human;
	human.TakeApple(apple);

	return 0;
}

void Human::TakeApple(Apple &apple) {
	cout << "weight = " << apple.weight << "\ncolor = " << apple.color << endl;
}