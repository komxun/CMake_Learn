#include <iostream>
#include "../SomeLibDemo/adder.h"

int main()
{
    std::cout << "2 + 3 = ";
    std::cout << komsunmath::add(2,3) << std::endl;
    return 0;
}