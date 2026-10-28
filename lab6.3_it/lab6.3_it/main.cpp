#include <iostream>
#include <string>

using namespace std;

// Звичайна функція
void Print(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Шаблонна функція
template <typename T>
void Print(T* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

#ifndef TEST_MODE
int main() {
    const int n = 5;

    int a[n] = { 10, 20, 30, 40, 50 };
    cout << "Print(a, n)           : ";
    Print(a, n);

    cout << "Print<int>(a, n)      : ";
    Print<int>(a, n);

    double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "Print<double>(b, n)   : ";
    Print(b, n);

    string c[n] = { "One", "Two", "Three", "Four", "Five" };
    cout << "Print<string>(c, n)   : ";
    Print(c, n);

    return 0;
}
#endif
