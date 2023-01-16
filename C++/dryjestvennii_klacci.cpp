#include <iostream>

using namespace std;

class Value_2;

class Value_1 {
public:
	Value_1(int x, int y, int z) {
		this->x = x, this->y = y, this->z = z;
	}
private:
	int x = 0, y = 0, z = 0;
	friend Value_2;
};

class Value_2 {
public:
	void Print(Value_1 &value_1) {
		cout << "x = " << value_1.x << "\n" << "y = " << value_1.y << "\n" << "z = " << value_1.z;
	}
};

signed main() {
	Value_1 value_1(1, 2, 3); Value_2 value_2;
	value_2.Print(value_1);
	
	return 0;
}