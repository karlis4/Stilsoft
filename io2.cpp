#include <iostream>


int readNumber() {
    std::cout << "¬ведите целое число: ";
    int num;
    std::cin >> num;
    return num;
}


void writeAnswer(int result) {
    std::cout << "—умма чисел равна: " << result << std::endl;
}