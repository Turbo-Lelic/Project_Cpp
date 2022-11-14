#include <iostream>
#include <locale>

using namespace std;

class Konstrukt {
private:
	int x = 0;
	int y = 0;
public:
	Konstrukt(int valueX, int valueY) {
		x = valueX;
		y = valueY;
	}

	void Print() {
		cout << "x = " << x << "\ny = " << y << "\n\n";
	}
};

int main(void) {
	setlocale(LC_ALL, "Russian");

	Konstrukt k1(2, 5);
	Konstrukt k2(3, 2);
	k1.Print();
	k2.Print();

	return 0;
}