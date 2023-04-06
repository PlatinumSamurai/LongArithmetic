#ifndef LONGARITHMETICS_BIGNUMBER_H
#define LONGARITHMETICS_BIGNUMBER_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <string>
#include <cctype>


class BigNumber {
protected:
    std::vector<int8_t> number;

public:
    explicit BigNumber(const std::string &str = "0");
    friend BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs);
    friend BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs);
    friend std::ostream &operator<<(std::ostream &out, const BigNumber &number);

};


#endif //LONGARITHMETICS_BIGNUMBER_H
