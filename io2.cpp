#include <iostream>


int readNumber() {
    std::cout << "������� ����� �����: ";
    int num;
    std::cin >> num;
    return num;
}


void writeAnswer(int result) {
    std::cout << "����� ����� �����: " << result << std::endl;
}