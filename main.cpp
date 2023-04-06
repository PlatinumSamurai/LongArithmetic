#include <iostream>
#include "BigNumber.h"
#include <cassert>


int main() {
    BigNumber num1("16");
    BigNumber num2("11");
//    BigNumber num3 = num1 + num2;

    std::cout << (num1 < num2) << std::endl;

    return 0;
}
