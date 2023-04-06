#include <iostream>
#include "BigNumber.h"
#include <cassert>


int main() {
    BigNumber num1("1000");
    BigNumber num2("1");
    BigNumber num3 = num1 - num2;

    std::cout << num3 << std::endl;

    return 0;
}
