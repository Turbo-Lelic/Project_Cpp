#include <iostream>

using namespace std;

enum seasons {
	spring = 1,
	summer,
	autumn,
	winter
};

signed main() {
	seasons object_1 = autumn;
	seasons object_2 = seasons(3);

	cout << "Season: " << object_1 << endl;
	cout << "Season: " << object_2 << endl;
	cout << "Season: " << seasons::autumn << endl;

	return 0;
}