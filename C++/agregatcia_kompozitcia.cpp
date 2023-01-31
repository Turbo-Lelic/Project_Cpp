#include <iostream>
#include <string>

using namespace std;
namespace FirstSpace {
	namespace SecondSpace {
		void func() {
			cout << "|---start---|\n";
		}
	}

	class Cap { //агрегация
	public:
		string GetColor() {
			return color;
		}
	private:
		string color = "green";
	};

	class Moneken { //агрегация
	public:
		void PutOnCap() { //агрегация
			cout << "Моя кепка " << cap.GetColor() << " цвета была надета на моникена..." << endl;
		}
	private:
		Cap cap;
	};

	class Human { //композиция
	public:
		void Think() { //композиция
			brain.Think();
		}
		void PutOnCap() { //агрегация
			cout << "Моя кепка " << cap.GetColor() << " цвета была надета..." << endl;
		}
	private:
		class Brain {
		public:
			void Think() {
				cout << "Думаю..." << endl;
			}
		};
		Brain brain;
		Cap cap;
	};
}

signed main() {
	setlocale(LC_ALL, "Russian");

	FirstSpace::Human human; FirstSpace::Moneken moneken;
	FirstSpace::SecondSpace::func();
	human.Think(); human.PutOnCap();
	moneken.PutOnCap();

	return 0;
}