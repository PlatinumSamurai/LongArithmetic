#include <iostream>
#include "BigNumber.h"
#include <cassert>


int main() {
//    BigNumber num1("234356465768");
//    BigNumber num2("0");
//    BigNumber num3 = num1 / num2;
//
//    std::cout << num3 << std::endl;

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


    // Operator - tests
    assert(BigNumber("6") - BigNumber("5") == BigNumber("1"));
    assert(BigNumber("6") - BigNumber("6") == BigNumber("0"));
    assert(BigNumber("16") - BigNumber("6") == BigNumber("10"));
    assert(BigNumber("5") - BigNumber("6") == BigNumber("-1"));
    assert(BigNumber("-1") - BigNumber("1") == BigNumber("-2"));
    assert(BigNumber("-9") - BigNumber("1") == BigNumber("-10"));
    assert(BigNumber("-99") - BigNumber("5") == BigNumber("-104"));
    assert(BigNumber("-1") - BigNumber("-1") == BigNumber("0"));
    assert(BigNumber("5") - BigNumber("20") == BigNumber("-15"));
    assert(BigNumber("-15") - BigNumber("-6") == BigNumber("-9"));
    assert(BigNumber("100") - BigNumber("95") == BigNumber("5"));


    // Operator * tests
    assert(BigNumber("2") * BigNumber("2") == BigNumber("4"));
    assert(BigNumber("2") * BigNumber("3") == BigNumber("6"));
    assert(BigNumber("2") * BigNumber("6") == BigNumber("12"));
    assert(BigNumber("24") * BigNumber("6") == BigNumber("144"));
    assert(BigNumber("-1") * BigNumber("6") == BigNumber("-6"));
    assert(BigNumber("-1") * BigNumber("16") == BigNumber("-16"));
    assert(BigNumber("-2") * BigNumber("16") == BigNumber("-32"));
    assert(BigNumber("-15") * BigNumber("15") == BigNumber("-225"));
    assert(BigNumber("-15") * BigNumber("-15") == BigNumber("225"));

    // Operator / tests
    assert(BigNumber("4") / BigNumber("1") == BigNumber("4"));
    assert(BigNumber("0") / BigNumber("1") == BigNumber("0"));
    assert(BigNumber("0") / BigNumber("-1") == BigNumber("0"));
    assert(BigNumber("4") / BigNumber("2") == BigNumber("2"));
    assert(BigNumber("6") / BigNumber("2") == BigNumber("3"));
    assert(BigNumber("9") / BigNumber("3") == BigNumber("3"));
    assert(BigNumber("25") / BigNumber("5") == BigNumber("5"));
    assert(BigNumber("100") / BigNumber("5") == BigNumber("20"));
    assert(BigNumber("100") / BigNumber("20") == BigNumber("5"));
    assert(BigNumber("100") / BigNumber("4") == BigNumber("25"));
    assert(BigNumber("10000") / BigNumber("100") == BigNumber("100"));
    assert(BigNumber("25") / BigNumber("4") == BigNumber("6"));
    assert(BigNumber("10020") / BigNumber("100") == BigNumber("100"));
    assert(BigNumber("10101") / BigNumber("100") == BigNumber("101"));
    assert(BigNumber("12345") / BigNumber("678") == BigNumber("18"));
    assert(BigNumber("34566574545") / BigNumber("2645") == BigNumber("13068648"));
    assert(BigNumber("98356742983549357206") / BigNumber("46734137658") == BigNumber("2104601644"));
    assert(BigNumber("-98356742983549357206") / BigNumber("46734137658") == BigNumber("-2104601644"));
    assert(BigNumber("98356742983549357206") / BigNumber("-46734137658") == BigNumber("-2104601644"));
    assert(BigNumber("-98356742983549357206") / BigNumber("-46734137658") == BigNumber("2104601644"));



    std::cerr << "All tests are passed!" << std::endl;

    return 0;
}
