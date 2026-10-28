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

int MinIndex(const int* a, const int size) {
    int min_i = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] < a[min_i]) {
            min_i = i;
        }
    }
    return min_i;
}

int MaxIndex(const int* a, const int size) {
    int max_i = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] > a[max_i]) {
            max_i = i;
        }
    }
    return max_i;
}

double MeanIndices(const int* a, const int size) {
    return (MinIndex(a, size) + MaxIndex(a, size)) / 2.0;
}

#ifndef TEST_MODE
int main() {
    srand((unsigned)time(NULL));

    const int size = 15;
    int a[size];
    int Low = -20;
    int High = 20;

    Create(a, size, Low, High);
    
    cout << "Original array:" << endl;
    Print(a, size);

    cout << "Min element index: " << MinIndex(a, size) << endl;
    cout << "Max element index: " << MaxIndex(a, size) << endl;
    cout << "Mean of indices: " << MeanIndices(a, size) << endl;

    return 0;
}
#endif
