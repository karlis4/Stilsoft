#include <iostream>


void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {

    setlocale(LC_ALL, "Rus");

    int x = 10;
    int y = 20;
    std::cout << "Перед обменом: x = " << x << ", y = " << y << '\n';

    swap(x, y);

    std::cout << "После обмена: x = " << x << ", y = " << y << '\n';
    return 0;
}
