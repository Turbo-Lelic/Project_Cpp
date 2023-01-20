#include <iostream>

using namespace std;

class Apple {
public:
	Apple(int weight, string color) {
		this->weight = weight; this->color = color;
		cnt++; id = cnt;
	}
	int GetId() {
		return id;
	}
	static int GetCnt() {
		return cnt;
	}
	void static ChangetColor(Apple &apple, string color) {
		apple.color = color;
	}
	void ChangetColorNoStatic(string color) {
		this->color = color;
	}
private:
	int id;
	int weight;
	string color;
	static int cnt;
};
int Apple::cnt = 0;

signed main() {
	Apple apple1(100, "Green"), apple2(200, "Yellow"), apple3(300, "Red");
	apple1.ChangetColor(apple1, "Red"); apple2.ChangetColor(apple2, "Yellow"); apple3.ChangetColor(apple3, "Green");
	apple1.ChangetColorNoStatic("Green"); apple2.ChangetColorNoStatic("Yellow"); apple3.ChangetColorNoStatic("Red");
	cout << apple1.GetId() << endl << apple2.GetId() << endl << apple3.GetId() << endl;
	cout << apple1.GetCnt(); //cout << Apple::GetCnt();

	return 0;
}