#include <iostream>


void printCharacters(const char* str) {
    while (*str != '\0') { 
        std::cout << *str; 
        ++str;             
    }
    std::cout << '\n';     
}

int main() {
    const char* message = "Hello, world!";
    printCharacters(message); 
    return 0;
}
