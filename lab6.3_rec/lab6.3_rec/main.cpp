#include <iostream>
#include <string>

using namespace std;

// Звичайна рекурсивна функція
void Print(int* a, const int size, int i) {
    if (i < size) {
        cout << a[i] << " ";
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

// Шаблонна рекурсивна функція
template <typename T>
void Print(T* a, const int size, int i) {
    if (i < size) {
        cout << a[i] << " ";
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

#ifndef TEST_MODE
int main() {
    const int n = 5;

    int a[n] = { 10, 20, 30, 40, 50 };
    cout << "Print(a, n, 0)           : ";
    Print(a, n, 0);

    cout << "Print<int>(a, n, 0)      : ";
    Print<int>(a, n, 0);

    double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << "Print<double>(b, n, 0)   : ";
    Print(b, n, 0);

    string c[n] = { "One", "Two", "Three", "Four", "Five" };
    cout << "Print<string>(c, n, 0)   : ";
    Print(c, n, 0);

    return 0;
}
#endif
