
#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds) {
   
    double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    
    if (currentHeight < 0) {
        return 0;
    }

    return currentHeight;
}

int main() {

    setlocale(LC_ALL, "Rus");

    std::cout << "Введите высоту башни в метрах: ";
    double initialHeight;
    std::cin >> initialHeight;

   
    for (int seconds = 0; seconds <= 5; ++seconds) {
        double height = calculateHeight(initialHeight, seconds);
        std::cout << "Через " << seconds << " сек. мяч на высоте: " << height << " м\n";
    }

    return 0;
}
