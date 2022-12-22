#include <iostream>

using namespace std;

enum PCState {
	OFF = 0,
	ON,
	SLEEP,
	REPET
};

class PC {
public:
	void set(PCState state) {
		this->state = state;
	}
	PCState get() {
		return state;
	}
private:
	PCState state = OFF;
};

signed main() {
	PC pc;
	pc.set(PCState::ON);

	switch (pc.get()) {
	case PCState::OFF:	
		cout << "PC - OFF";
		break;
	case PCState::ON:
		cout << "PC - ON";
		break;
	case PCState::SLEEP:
		cout << "PC - SLEEP";
		break;
	case PCState::REPET:
		cout << "PC - REPET";
		break;
	}

	return 0;
}