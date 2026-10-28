#include <iostream>
#include <cassert>

#define TEST_MODE
#include "../../lab6.1_rec/lab6.1_rec/main.cpp"

using namespace std;

int main() {
    const int size = 5;
    int test_array[size] = {-10, -5, 0, 15, -20};
    
    assert(Count(test_array, size) == 3);
    assert(Sum(test_array, size) == -30);
    
    Replace(test_array, size);
    
    assert(test_array[0] == 0);
    assert(test_array[1] == -5);
    assert(test_array[2] == 0);
    assert(test_array[3] == 15);
    assert(test_array[4] == 0);

    cout << "Lab 6.1 (Recursive): All Unit Tests passed successfully!" << endl;
    return 0;
}
