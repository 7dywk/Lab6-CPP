#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void Create(double* a, const int size, const double Low, const double High, int i = 0) {
    if (i < size) {
        a[i] = Low + (High - Low) * rand() / (double)RAND_MAX;
        Create(a, size, Low, High, i + 1);
    }
}

void Print(const double* a, const int size, int i = 0) {
    if (i < size) {
        cout << setw(8) << setprecision(2) << fixed << a[i];
        Print(a, size, i + 1);
    } else {
        cout << endl;
    }
}

double SumOddIndices(const double* a, const int size, int i = 1) {
    if (i < size) {
        return a[i] + SumOddIndices(a, size, i + 2);
    }
    return 0;
}

int FirstNegativeIndex(const double* a, const int size, int i = 0) {
    if (i >= size) return -1;
    if (a[i] < 0) return i;
    return FirstNegativeIndex(a, size, i + 1);
}

int LastNegativeIndex(const double* a, int i) {
    if (i < 0) return -1;
    if (a[i] < 0) return i;
    return LastNegativeIndex(a, i - 1);
}

double SumRange(const double* a, int current, int end) {
    if (current < end) {
        return a[current] + SumRange(a, current + 1, end);
    }
    return 0;
}

double SumBetweenNegatives(const double* a, const int size) {
    int first = FirstNegativeIndex(a, size, 0);
    int last = LastNegativeIndex(a, size - 1);
    
    if (first == -1 || first == last || first + 1 == last) {
        return 0;
    }
    return SumRange(a, first + 1, last);
}

void FillZeros(double* a, const int size, int j) {
    if (j < size) {
        a[j] = 0.0;
        FillZeros(a, size, j + 1);
    }
}

void Compress(double* a, const int size, int i = 0, int j = 0) {
    if (i < size) {
        if (abs(a[i]) > 1.0) {
            a[j] = a[i];
            Compress(a, size, i + 1, j + 1);
        } else {
            Compress(a, size, i + 1, j);
        }
    } else {
        FillZeros(a, size, j);
    }
}

#ifndef TEST_MODE
int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) return 0;

    double* a = new double[n];
    double Low = -5.0;
    double High = 5.0;

    Create(a, n, Low, High, 0);
    
    cout << "Original array (recursive):" << endl;
    Print(a, n, 0);

    cout << "Sum of elements with odd indices: " << SumOddIndices(a, n, 1) << endl;
    cout << "Sum between first and last negative: " << SumBetweenNegatives(a, n) << endl;

    Compress(a, n, 0, 0);
    
    cout << "Compressed array (recursive):" << endl;
    Print(a, n, 0);

    delete[] a;

    return 0;
}
#endif
