#include <iostream>
#include "BigNumber.h"
#include <cassert>


int main() {
    BigNumber num1("999");
    BigNumber num2("1");
    BigNumber num3 = num1 + num1;

    std::cout << num3 << std::endl;

    return 0;
}
