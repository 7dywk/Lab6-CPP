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

int MinIndex(const int* a, const int size, int i = 1, int min_i = 0) {
    if (i < size) {
        if (a[i] < a[min_i]) {
            min_i = i;
        }
        return MinIndex(a, size, i + 1, min_i);
    }
    return min_i;
}

int MaxIndex(const int* a, const int size, int i = 1, int max_i = 0) {
    if (i < size) {
        if (a[i] > a[max_i]) {
            max_i = i;
        }
        return MaxIndex(a, size, i + 1, max_i);
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

    Create(a, size, Low, High, 0);
    
    cout << "Original array (recursive):" << endl;
    Print(a, size, 0);

    cout << "Min element index: " << MinIndex(a, size) << endl;
    cout << "Max element index: " << MaxIndex(a, size) << endl;
    cout << "Mean of indices: " << MeanIndices(a, size) << endl;

    return 0;
}
#endif
