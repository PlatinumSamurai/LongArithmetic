#include <iostream>
#include "BigNumber.h"
#include <cassert>


int main() {
    BigNumber num1("5");
    BigNumber num2("6");
    BigNumber num3 = num1 - num2;

    std::cout << num3 << std::endl;

    // Abs function tests
    assert(BigNumber("1").abs() == BigNumber("1"));
    assert(BigNumber("-1").abs() == BigNumber("1"));
    assert(BigNumber("0").abs() == BigNumber("0"));

    // Operator > tests
    assert(BigNumber("1") > BigNumber("0") == 1);
    assert(BigNumber("16") > BigNumber("14") == 1);
    assert(BigNumber("1") > BigNumber("-1") == 1);
    assert(BigNumber("1") > BigNumber("-11") == 1);
    assert(BigNumber("-1") > BigNumber("-2") == 1);
    assert(BigNumber("-11") > BigNumber("-12") == 1);
    assert(BigNumber("-97") > BigNumber("-99") == 1);
    assert(BigNumber("0") > BigNumber("1") == 0);
    assert(BigNumber("14") > BigNumber("16") == 0);
    assert(BigNumber("-1") > BigNumber("1") == 0);
    assert(BigNumber("-11") > BigNumber("1") == 0);
    assert(BigNumber("-2") > BigNumber("-1") == 0);
    assert(BigNumber("-12") > BigNumber("-11") == 0);
    assert(BigNumber("-99") > BigNumber("-97") == 0);
    assert(BigNumber("1") > BigNumber("1") == 0);
    assert(BigNumber("-1") > BigNumber("-1") == 0);
    assert(BigNumber("0") > BigNumber("-1") == 1);
    assert(BigNumber("0") > BigNumber("-1123") == 1);


    // Operator < tests
    assert(BigNumber("1") < BigNumber("0") == 0);
    assert(BigNumber("16") < BigNumber("14") == 0);
    assert(BigNumber("1") < BigNumber("-1") == 0);
    assert(BigNumber("1") < BigNumber("-11") == 0);
    assert(BigNumber("-1") < BigNumber("-2") == 0);
    assert(BigNumber("-11") < BigNumber("-12") == 0);
    assert(BigNumber("-97") < BigNumber("-99") == 0);
    assert(BigNumber("0") < BigNumber("1") == 1);
    assert(BigNumber("14") < BigNumber("16") == 1);
    assert(BigNumber("-1") < BigNumber("1") == 1);
    assert(BigNumber("-11") < BigNumber("1") == 1);
    assert(BigNumber("-2") < BigNumber("-1") == 1);
    assert(BigNumber("-12") < BigNumber("-11") == 1);
    assert(BigNumber("-99") < BigNumber("-97") == 1);
    assert(BigNumber("1") < BigNumber("1") == 0);
    assert(BigNumber("-1") < BigNumber("-1") == 0);
    assert(BigNumber("-111") < BigNumber("0") == 1);
    assert(BigNumber("-1123") < BigNumber("0") == 1);


    // Operator >= tests
    assert(BigNumber("1") >= BigNumber("0") == 1);
    assert(BigNumber("16") >= BigNumber("14") == 1);
    assert(BigNumber("1") >= BigNumber("-1") == 1);
    assert(BigNumber("1") >= BigNumber("-11") == 1);
    assert(BigNumber("-1") >= BigNumber("-2") == 1);
    assert(BigNumber("-11") >= BigNumber("-12") == 1);
    assert(BigNumber("-97") >= BigNumber("-99") == 1);
    assert(BigNumber("0") >= BigNumber("1") == 0);
    assert(BigNumber("14") >= BigNumber("16") == 0);
    assert(BigNumber("-1") >= BigNumber("1") == 0);
    assert(BigNumber("-11") >= BigNumber("1") == 0);
    assert(BigNumber("-2") >= BigNumber("-1") == 0);
    assert(BigNumber("-12") >= BigNumber("-11") == 0);
    assert(BigNumber("-99") >= BigNumber("-97") == 0);
    assert(BigNumber("1") >= BigNumber("1") == 1);
    assert(BigNumber("-1") >= BigNumber("-1") == 1);

    // Operator <= tests
    assert(BigNumber("1") <= BigNumber("0") == 0);
    assert(BigNumber("16") <= BigNumber("14") == 0);
    assert(BigNumber("1") <= BigNumber("-1") == 0);
    assert(BigNumber("1") <= BigNumber("-11") == 0);
    assert(BigNumber("-1") <= BigNumber("-2") == 0);
    assert(BigNumber("-11") <= BigNumber("-12") == 0);
    assert(BigNumber("-97") <= BigNumber("-99") == 0);
    assert(BigNumber("0") <= BigNumber("1") == 1);
    assert(BigNumber("14") <= BigNumber("16") == 1);
    assert(BigNumber("-1") <= BigNumber("1") == 1);
    assert(BigNumber("-11") <= BigNumber("1") == 1);
    assert(BigNumber("-2") <= BigNumber("-1") == 1);
    assert(BigNumber("-12") <= BigNumber("-11") == 1);
    assert(BigNumber("-99") <= BigNumber("-97") == 1);
    assert(BigNumber("1") <= BigNumber("1") == 1);
    assert(BigNumber("-1") <= BigNumber("-1") == 1);



    std::cerr << "All tests are passed!" << std::endl;

    return 0;
}
