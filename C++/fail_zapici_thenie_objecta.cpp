#include <windows.h>
#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

class test {
public:
	test(int x, int y, int z) {
		this->x = x, this->y = y, this->z = z;
	}
	void print() {
		cout << "x - " << x << " y - " << y << " z - " << z << endl;
	}
private:
	int x, y, z;
};	

signed main() {
	setlocale(LC_ALL, "Russian");

	int x, y, z; cin >> x >> y >> z;

	test object(x, y, z); test null_object(0, 0, 0);
	fstream input; ifstream output;

	input.open("file.txt", ofstream::app);
	if (!input.is_open()) {
		cout << "fail.txt не может быть изменен\n";
	} else if (input.is_open()) {
		cout << "fail.txt может быть изменен\n";
		input.write((char*)&object, sizeof(test));
	}
	input.close();

	output.open("file.txt");
	if (!output.is_open()) {
		cout << "fail.txt не может быть открыт\n";
		return 0;
	} else if (output.is_open()) {
		cout << "fail.txt может быть открыт\n";
		
		while (output.read((char*)&null_object, sizeof(test))) {
			null_object.print();
		}
	}
	output.close();
	Sleep(5000);

	return 0;
}