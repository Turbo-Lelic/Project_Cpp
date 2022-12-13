#include <iostream>

using namespace std;
namespace second_namespace {
	int second = 1;
	void func() {
		cout << "second\n";
	}
}
namespace first_namespace {
	int first = 2;
	void func() {
		cout << "first\n";
	}
}
namespace repet {
	namespace first_namespace {
		int first = 2;
		void func() {
			cout << "first\n";
		}
	}
}
namespace test {
	char arr[5] = {'t', 'e', 's', 't', '\0'};
	void func() {
		cout << "test\n";
	}
}
using namespace test;

signed main() {
	second_namespace::func();
	first_namespace::func();
	repet::first_namespace::func();
	func();

	return 0;
}