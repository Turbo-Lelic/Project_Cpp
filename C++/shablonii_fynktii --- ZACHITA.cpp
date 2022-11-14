#include <iostream>
#include <locale>

using namespace std;

template <typename T>
T sum1(T a, T b) {
    return a + b;
}

template <typename T1, typename T2>
T1 sum2(T1 a, T2 b) {
    return a + b;
}

template <typename T3>
T3 size(T3 a) {
    return sizeof(a);
}

int main(void) {
    setlocale(LC_ALL, "Russian");
        
    cout << sum1(5, 10) << "\n";
    cout << sum1(5.5, 10.0) << "\n";
    cout << sum2(5, 10) << "\n";
    cout << sum2(5, 10.0) << "\n";
    cout << size(5) << "\n";

    return 0;
}