#include <iostream>
#include <locale>

using namespace std;

class Point {
private:
	int x = 0;
	int y = 0;
public:
	int GetX() {
		return x;
	}	

	int GetY() {
		return y;
	}

	void SetY(int valueY) {
		y = valueY;
	}

	void SetX(int valueX) {
		x = valueX;
	}

	void Print() {
		cout << "x = " << x << "\ny = " << y;
	}
};

int main(void) {
	setlocale(LC_ALL, "Russian");

	Point a;
	a.SetX(2);
	a.SetY(5);
	a.Print();

	return 0;
}