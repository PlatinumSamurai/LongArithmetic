#include "BigNumber.h"

BigNumber::BigNumber(const std::string &str) {
    number.reserve(str.size());
    for(const char item : str) {
        if(std::isdigit(item)) {
            number.insert(number.begin(), item - '0');
        }
    }
}


std::ostream &operator<<(std::ostream &out, const BigNumber &number) {
    for(auto it = number.number.rbegin(); it != number.number.rend(); ++it) {
        out << short(*it);
    }

    return out;
}

BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs) {
    BigNumber result;
    auto &term = const_cast<BigNumber&>(rhs);

    if(lhs.number.size() > rhs.number.size()) {
        result = lhs;
    } else {
        result = rhs;
        term = lhs;
    }

    for(int i = 0; i < term.number.size(); ++i) {
        result.number.at(i) += term.number.at(i);
    }

    for(int i = 0; i < result.number.size(); ++i) {
        if(result.number.at(i) >= 10) {
            result.number.at(i) -= 10;
            if(i < result.number.size() - 1) {
                result.number.at(i + 1)++;
            } else {
                result.number.push_back(1);
            }
        }
    }

    return result;
}
