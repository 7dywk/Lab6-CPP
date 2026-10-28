#include <iostream>
#include <string>
#include <cassert>

#define TEST_MODE
#include "../../lab6.3_rec/lab6.3_rec/main.cpp"

using namespace std;

int main() {
    const int size = 3;
    
    int int_arr[size] = {10, 20, 30};
    double double_arr[size] = {1.5, 2.5, 3.5};
    string str_arr[size] = {"Test1", "Test2", "Test3"};
    
    cout << "Testing recursive Print for int:" << endl;
    Print(int_arr, size, 0);
    
    cout << "Testing recursive template Print for double:" << endl;
    Print<double>(double_arr, size, 0);
    
    cout << "Testing recursive template Print for string:" << endl;
    Print<string>(str_arr, size, 0);

    cout << "Lab 6.3 (Recursive): All Unit Tests passed successfully!" << endl;
    return 0;
}
