#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int Count(const int* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] <= 0 && i % 2 == 0) {
            count++;
        }
    }
    return count;
}

int Sum(const int* a, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] <= 0 && i % 2 == 0) {
            sum += a[i];
        }
    }
    return sum;
}

void Replace(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] <= 0 && i % 2 == 0) {
            a[i] = 0;
        }
    }
}

#ifndef TEST_MODE
int main() {
    srand((unsigned)time(NULL));

    const int size = 26;
    int a[size];
    int Low = -40;
    int High = 20;

    Create(a, size, Low, High);
    
    cout << "Original array:" << endl;
    Print(a, size);

    int count = Count(a, size);
    int sum = Sum(a, size);

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    Replace(a, size);
    
    cout << "Modified array:" << endl;
    Print(a, size);

    return 0;
}
#endif
