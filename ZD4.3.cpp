#include <iostream>

int main() {

    setlocale(LC_ALL, "Rus");

    double num1, num2;
    char operation;
    std::cout << "Введите два числа с плавающей запятой: ";
    std::cin >> num1 >> num2;
    std::cout << "Введите математический символ (+, -, * или /): ";
    std::cin >> operation;

    switch (operation) {
    case '+':
        std::cout << "Результат: " << num1 + num2 << std::endl;
        break;
    case '-':
        std::cout << "Результат: " << num1 - num2 << std::endl;
        break;
    case '*':
        std::cout << "Результат: " << num1 * num2 << std::endl;
        break;
    case '/':
        if (num2 != 0.0) {
            std::cout << "Результат: " << num1 / num2 << std::endl;
        } 
        break;
        
    }

    return 0;
}
