#include <iostream>
#include <string>

using namespace std;

class Class {
public:
	static int count; 

	Class(int weight, string color) {
		this->weight = weight; this->color = color;
		count++;
	}
private:
	int weight;
	string color;
};
int Class::count = 0;

signed main() {
	Class apple_1(100, "red"), apple_2(200, "green");
	cout << apple_1.count << "\n"; //1
	cout << Class::count << "\n"; //2

	return 0;
}