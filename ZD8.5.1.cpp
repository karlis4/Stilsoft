#include <iostream>

template <typename T>
T mult(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << mult(3, 3) << '\n';   
    std::cout << mult(1.2, 2.4) << '\n'; 

    return 0;
}


