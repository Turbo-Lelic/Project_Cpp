#include <iostream>
#include <vector>

typedef std::vector<int> int_vector; typedef std::vector<double> int_vector;
typedef std::vector<float> int_vector; typedef std::vector<char> int_vector;

signed main() {
	int_vector arr(5);

	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i]; std::cout << arr[i] << ' ';
	}

	return 0;
}