#ifndef LONGARITHMETICS_BIGNUMBER_H
#define LONGARITHMETICS_BIGNUMBER_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


class BigNumber {
private:
    std::vector<int8_t> number;

    int reduction();

public:
    explicit BigNumber(const std::string &str = "0");
    BigNumber operator+(const BigNumber &rhs) const;
    BigNumber operator+=(const BigNumber &rhs);
    BigNumber operator-(const BigNumber &rhs);
    BigNumber operator-=(const BigNumber &rhs);
    BigNumber operator*(const BigNumber &rhs);
    BigNumber operator*=(const BigNumber &rhs);
    BigNumber operator/(const BigNumber &rhs) const;
    BigNumber operator/=(const BigNumber &rhs);
    BigNumber operator%(const BigNumber &rhs) const;
    BigNumber operator%=(const BigNumber &rhs);
    bool operator>(const BigNumber &rhs) const;
    bool operator<(const BigNumber &rhs) const;
    bool operator==(const BigNumber &rhs) const;
    bool operator>=(const BigNumber &rhs) const;
    bool operator<=(const BigNumber &rhs) const;
    bool operator!=(const BigNumber &rhs) const;
    friend std::ostream &operator<<(std::ostream &out, const BigNumber &number);

    [[nodiscard]] BigNumber abs() const;

};


template <typename T> BigNumber to_BigNumber(const T &num) {
    std::vector<std::string> types = {"e", "f", "d", typeid(BigNumber).name()};

    for(const auto &item : types) {
        if(typeid(num).name() == item) {
            throw std::bad_cast();
        }
    }

    try {
        return BigNumber(std::to_string(num));
    } catch(...) {

    }

    return BigNumber();
}


template <typename T> BigNumber operator+(T lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result + rhs;
}


template <typename T> BigNumber operator+(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs.operator+(result);
}


template <typename T> BigNumber operator-(T lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result - rhs;
}


template <typename T> BigNumber operator-(const BigNumber &lhs, const T &rhs) {
    return (rhs - lhs) * (-1);
}


template <typename T> BigNumber operator*(T lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result * rhs;
}


template <typename T> BigNumber operator*(const BigNumber &lhs, const T &rhs) {
    return rhs * lhs;
}


template <typename T> BigNumber operator/(T lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result / rhs;
}


template <typename T> BigNumber operator/(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs / result;
}


template <typename T> BigNumber operator%(T lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result % rhs;
}


template <typename T> BigNumber operator%(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs % result;
}


template <typename T>
bool operator>(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result > rhs;
}


template <typename T>
bool operator>(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs > result;
}


template <typename T>
bool operator<(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result < rhs;
}


template <typename T>
bool operator<(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs < result;
}


template <typename T>
bool operator==(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result == rhs;
}


template <typename T>
bool operator==(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs == result;
}


template <typename T>
bool operator>=(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result >= rhs;
}


template <typename T>
bool operator>=(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs >= result;
}


template <typename T>
bool operator<=(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result <= rhs;
}


template <typename T>
bool operator<=(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs <= result;
}


template <typename T>
bool operator!=(const T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result != rhs;
}


template <typename T>
bool operator!=(const BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs != result;
}


template <typename T>
BigNumber operator+=(BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs += result;
}


template <typename T>
BigNumber operator+=(T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result += rhs;
}


template <typename T>
BigNumber operator-=(BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs -= result;
}


template <typename T>
BigNumber operator-=(T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result -= rhs;
}


template <typename T>
BigNumber operator*=(BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs *= result;
}


template <typename T>
BigNumber operator*=(T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result *= rhs;
}


template <typename T>
BigNumber operator/=(BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs /= result;
}


template <typename T>
BigNumber operator/=(T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result /= rhs;
}


template <typename T>
BigNumber operator%=(BigNumber &lhs, const T &rhs) {
    BigNumber result = to_BigNumber(rhs);

    return lhs %= result;
}


template <typename T>
BigNumber operator%=(T &lhs, const BigNumber &rhs) {
    BigNumber result = to_BigNumber(lhs);

    return result %= rhs;
}


#endif //LONGARITHMETICS_BIGNUMBER_H
