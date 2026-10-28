#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void Create(double* a, const int size, const double Low, const double High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + (High - Low) * rand() / (double)RAND_MAX;
    }
}

void Print(const double* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << setprecision(2) << fixed << a[i];
    }
    cout << endl;
}

double SumOddIndices(const double* a, const int size) {
    double sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += a[i];
    }
    return sum;
}

int FirstNegativeIndex(const double* a, const int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) return i;
    }
    return -1;
}

int LastNegativeIndex(const double* a, const int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (a[i] < 0) return i;
    }
    return -1;
}

double SumBetweenNegatives(const double* a, const int size) {
    int first = FirstNegativeIndex(a, size);
    int last = LastNegativeIndex(a, size);
    
    if (first == -1 || first == last || first + 1 == last) {
        return 0;
    }

    double sum = 0;
    for (int i = first + 1; i < last; i++) {
        sum += a[i];
    }
    return sum;
}

void Compress(double* a, const int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (abs(a[i]) > 1.0) {
            a[j] = a[i];
            j++;
        }
    }
    for (int i = j; i < size; i++) {
        a[i] = 0.0;
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

    Create(a, n, Low, High);
    
    cout << "Original array:" << endl;
    Print(a, n);

    cout << "Sum of elements with odd indices: " << SumOddIndices(a, n) << endl;
    cout << "Sum between first and last negative: " << SumBetweenNegatives(a, n) << endl;

    Compress(a, n);
    
    cout << "Compressed array:" << endl;
    Print(a, n);

    delete[] a;

    return 0;
}
#endif
