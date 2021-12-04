#include <iostream>

#include "day3.h"



int main() {
    day3 daythree {};

    auto res = daythree.DayThreePartOne();
    std::cout << "Res: " << res << std::endl;

    res = daythree.DayThreePartTwo();
    std::cout << "Res: " << res << std::endl;

    return 0;
}
