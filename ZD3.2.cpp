#include <iostream>

int readNumber()
{
    std::cout << "Please enter a number: ";
    int num;
    std::cin >> num;
    return num;
}

void writeAnswer(int x)
{
    std::cout << "The quotient is: " << x << std::endl;
}

int main()
{
    int x = readNumber(); 
    int y = readNumber(); 
    if (y != 0) {
        writeAnswer(x / y); 
    }
    else {
        std::cout << "Error: Division by zero." << std::endl; 
    }

    return 0;
}
