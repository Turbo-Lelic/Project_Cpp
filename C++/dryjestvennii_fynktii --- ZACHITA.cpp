#include <iostream>
#include <string>  
#include <locale>

using namespace std;

template <class T>
class Auto {
public:
    Auto(T price, T weight, string name) {    
        this->price = price;
        this->weight = weight;
        this->name = name;
    }
private:
    T price;
    T weight;
    string name;
    
    friend void Print(Auto<int> &Auto);
};

int main(void) {
    setlocale(LC_ALL, "Russian");

    Auto<int> Tesla(10000, 250, "Tesla");
    
    Print(Tesla);

    return 0;
}

void Print(Auto<int> &Auto) {
    if (Auto.price >= 1000) {
        cout << "________________________________\n" << "Цена машины = " << Auto.price << " руб | Дорогая\n";
    } else if (Auto.price <= 999) {
        cout << "________________________________\n" << "Цена машины = " << Auto.price << " руб | Нормальная\n";
    }

    if (Auto.weight >= 1000) {
        cout << "________________________________\n" << "Вес машины = " << Auto.weight << " кг | Тяжелая\n________________________________\n";
    } else if (Auto.weight <= 500) {
        cout << "________________________________\n" << "Вес машины = " << Auto.weight << " кг | Легкая\n________________________________\n";
    }

    cout << "Имя машины = " << Auto.name << " | " << Auto.name << "\n________________________________";
}