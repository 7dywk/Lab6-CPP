#include <iostream>
#include <cassert>
#include <cmath>

#define TEST_MODE
#include "../../lab6.4_it/lab6.4_it/main.cpp"

using namespace std;

int main() {
    const int size = 6;
    double test_array[size] = {2.0, -1.5, 3.0, 0.5, -2.5, 4.0};
    
    // Порівняння дійсних чисел з похибкою 0.0001
    assert(abs(SumOddIndices(test_array, size) - 3.0) < 0.0001);
    assert(abs(SumBetweenNegatives(test_array, size) - 3.5) < 0.0001);
    
    Compress(test_array, size);
    
    assert(test_array[0] == 2.0);
    assert(test_array[1] == -1.5);
    assert(test_array[2] == 3.0);
    assert(test_array[3] == -2.5);
    assert(test_array[4] == 4.0);
    assert(test_array[5] == 0.0);

    cout << "Lab 6.4 (Iterative): All Unit Tests passed successfully!" << endl;
    return 0;
}
