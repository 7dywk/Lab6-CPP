#include <iostream>
#include <cassert>

#define TEST_MODE
#include "../../lab6.1_it/lab6.1_it/main.cpp"

using namespace std;

int main() {
    const int size = 5;
    // Створюємо масив, щоб перевірити умову: (<= 0) ТА (парний індекс)
    // Парні індекси (0, 2, 4) -> -10, 0, -20. Вони всі <= 0, тому підходять.
    // Непарні індекси (1, 3) -> -5, 15. Вони не підходять через індекс.
    int test_array[size] = {-10, -5, 0, 15, -20};
    
    // 1. Перевірка обчислення кількості (має бути 3 елементи)
    assert(Count(test_array, size) == 3);
    
    // 2. Перевірка обчислення суми: -10 + 0 + (-20) = -30
    assert(Sum(test_array, size) == -30);
    
    // 3. Перевірка заміни елементів нулями
    Replace(test_array, size);
    
    assert(test_array[0] == 0);   // Замінено
    assert(test_array[1] == -5);  // Не змінено (непарний індекс)
    assert(test_array[2] == 0);   // Замінено
    assert(test_array[3] == 15);  // Не змінено
    assert(test_array[4] == 0);   // Замінено

    cout << "Lab 6.1 (Iterative): All Unit Tests passed successfully!" << endl;

    return 0;
}
