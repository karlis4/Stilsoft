#include <iostream>
#include "io23.h"


int main() {

    setlocale(LC_ALL, "Rus");

    int num1 = readNumber(); 
    int num2 = readNumber(); 
    writeAnswer(num1 + num2); 
    return 0;
}