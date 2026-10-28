#include <iostream>
#include <string>
#include <cassert>

#define TEST_MODE

#include "../../lab6.3_it/lab6.3_it/main.cpp"

using namespace std;

int main() {
    const int size = 3;
    
    // Перевіряємо, що звичайна та шаблонна функції викликаються без помилок компіляції
    int int_arr[size] = {1, 2, 3};
    double double_arr[size] = {1.1, 2.2, 3.3};
    string str_arr[size] = {"A", "B", "C"};
    
    // Викликаємо функції всередині тесту, щоб переконатися в їх роботі
    cout << "Testing regular Print for int:" << endl;
    Print(int_arr, size);
    
    cout << "Testing template Print for int:" << endl;
    Print<int>(int_arr, size);
    
    cout << "Testing template Print for double:" << endl;
    Print<double>(double_arr, size);
    
    cout << "Testing template Print for string:" << endl;
    Print<string>(str_arr, size);
    
    // Якщо дійшли сюди без вильотів — тест успішний
    cout << "Lab 6.3 (Iterative): All Unit Tests passed successfully!" << endl;
    return 0;
}
