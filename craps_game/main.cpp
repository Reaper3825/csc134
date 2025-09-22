#include <iostream>
#include "roll.hpp"

int main() {
    std::cout << "Rolling a 6-sided die: " << roll(6) << std::endl;
    std::cout << "Rolling a 20-sided die: " << roll(20) << std::endl;

    return 0;
}
