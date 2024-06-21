#include <iostream>
#include <cmath>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    double height = calculateHeight(initialHeight, time);
    if (height > 0.0)
    {
        std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";
    }
    else
    {
        std::cout << "At " << time << " seconds, the ball has hit the ground.\n";
    }
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    int time = 0;
    while (calculateHeight(initialHeight, time) > 0.0)
    {
        calculateAndPrintHeight(initialHeight, time);
        ++time;
    }
    calculateAndPrintHeight(initialHeight, time); 

    return 0;
}
