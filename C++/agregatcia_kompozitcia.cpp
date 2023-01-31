#include <iostream>
#include <string>

using namespace std;
namespace FirstSpace {
	namespace SecondSpace {
		void func() {
			cout << "|---start---|\n";
		}
	}

	class Cap { //���������
	public:
		string GetColor() {
			return color;
		}
	private:
		string color = "green";
	};

	class Moneken { //���������
	public:
		void PutOnCap() { //���������
			cout << "��� ����� " << cap.GetColor() << " ����� ���� ������ �� ��������..." << endl;
		}
	private:
		Cap cap;
	};

	class Human { //����������
	public:
		void Think() { //����������
			brain.Think();
		}
		void PutOnCap() { //���������
			cout << "��� ����� " << cap.GetColor() << " ����� ���� ������..." << endl;
		}
	private:
		class Brain {
		public:
			void Think() {
				cout << "�����..." << endl;
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