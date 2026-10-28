#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i = 0) {
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(const int* a, const int size, int i = 0) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

int Count(const int* a, const int size, int i = 0) {
    if (i < size) {
        if (a[i] <= 0 && i % 2 == 0) {
            return 1 + Count(a, size, i + 1);
        } else {
            return Count(a, size, i + 1);
        }
    }
    return 0;
}

int Sum(const int* a, const int size, int i = 0) {
    if (i < size) {
        if (a[i] <= 0 && i % 2 == 0) {
            return a[i] + Sum(a, size, i + 1);
        } else {
            return Sum(a, size, i + 1);
        }
    }
    return 0;
}

void Replace(int* a, const int size, int i = 0) {
    if (i < size) {
        if (a[i] <= 0 && i % 2 == 0) {
            a[i] = 0;
        }
        Replace(a, size, i + 1);
    }
}

#ifndef TEST_MODE
int main() {
    srand((unsigned)time(NULL));

    const int size = 26;
    int a[size];
    int Low = -40;
    int High = 20;

    Create(a, size, Low, High, 0);
    
    cout << "Original array (recursive):" << endl;
    Print(a, size, 0);

    int count = Count(a, size, 0);
    int sum = Sum(a, size, 0);

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    Replace(a, size, 0);
    
    cout << "Modified array (recursive):" << endl;
    Print(a, size, 0);

    return 0;
}
#endif
