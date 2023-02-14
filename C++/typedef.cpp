#include <iostream>
#include <vector>

typedef std::vector<int> int_vector; typedef std::vector<double> double_vector;
typedef std::vector<float> float_vector; typedef std::vector<char> char_vector;

signed main() {
	int_vector arr(5);

	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i]; std::cout << arr[i] << ' ';
	}

	return 0;
}