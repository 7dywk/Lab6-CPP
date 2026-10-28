#include <iostream>
#include <cassert>

#define TEST_MODE
#include "../../lab6.2_rec/lab6.2_rec/main.cpp"

using namespace std;

int main() {
    const int size = 5;
    int test_array[size] = {10, -5, 20, 0, 15};
    

    assert(MinIndex(test_array, size) == 1);
    assert(MaxIndex(test_array, size) == 2);
    assert(MeanIndices(test_array, size) == 1.5);

    cout << "Lab 6.2 (Recursive): All Unit Tests passed successfully!" << endl;
    return 0;
}
