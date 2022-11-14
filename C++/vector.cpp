#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");

    vector<string> students;

    // буфер для ввода фамилии
    string buffer = "";

    cout << "Вводите фамилии. " << "По окончание ввода введите пустую строку" << "\n";

    do {
        getline(cin, buffer);
        if (buffer.size() > 0) {
            // добавление элемента в конец вектора
            students.push_back(buffer);
        }
    } while (buffer != "");

    // сохраняем количество элементов вектора для цикла
    int vector_size = students.size();

    cout << "Ваш вектор." << "\n";

    for (int i = 0; i < vector_size; i++) {
        cout << students[i] << "\n"; 
    }

    return 0;
}