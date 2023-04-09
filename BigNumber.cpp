#include "BigNumber.h"

// TODO reduction of insignificant zeros is needed

BigNumber::BigNumber(const std::string &str) {
    bool sign = false;
    number.reserve(str.size());
    for(const char item : str) {
        if(std::isdigit(item)) {
            number.insert(number.begin(), item - '0');
            if(sign) {
                *number.begin() *= -1;
                sign = !sign;
            }
        } else if(item == '-') {
            sign = true;
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
    BigNumber term;
    bool sign = false;


    if(lhs.number.size() >= rhs.number.size()) {
        result = lhs;
        term = rhs;
    } else {
        result = rhs;
        term = lhs;
    }


    if(result < BigNumber("0") and term >= BigNumber("0")) {
        result = result.abs();
        return term - result;
    } else if(result >= BigNumber("0") and term < BigNumber("0")) {
        term = term.abs();
        return result - term;
    } else if(result < BigNumber("0") and term < BigNumber("0")) {
        result = result.abs();
        term = term.abs();
        sign = true;
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

    if(sign) {
        *result.number.rbegin() *= -1;
    }

    return result;
}


BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs) {
    BigNumber result;
    BigNumber subtrahend;
    bool sign = false;
    bool permutation = false;


    if(lhs.number.size() >= rhs.number.size()) {
        result = lhs;
        subtrahend = rhs;
    } else {
        result = rhs;
        subtrahend = lhs;
        permutation = true;
    }

    if(result >= BigNumber("0") and subtrahend < BigNumber("0")) {
        result = result + subtrahend.abs();
        sign = true;
        if(permutation != sign) {
            return result * BigNumber("-1");
        } else {
            return result;
        }
    } else if(result < BigNumber("0") and subtrahend >= BigNumber("0")) {
        result = result.abs() + subtrahend.abs();
        sign = true;
        if(permutation != sign) {
            return result * BigNumber("-1");
        } else {
            return result;
        }
    }  else if(result < BigNumber("0") and subtrahend < BigNumber("0")) {
        result = result.abs();
        subtrahend = subtrahend.abs();
        sign = true;
    }

    for(int i = 0; i < subtrahend.number.size(); ++i) {
        result.number.at(i) -= subtrahend.number.at(i);
    }

    for(int i = 0; i < result.number.size(); ++i) {
        if(i < result.number.size() - 1) {
            if(result.number.at(i) < 0) {
                result.number.at(i) += 10;
                result.number.at(i + 1)--;
            }
        }
    }

    if(sign != permutation) {
        result = result * BigNumber("-1");
    }

    return result;
}


BigNumber operator*(const BigNumber &lhs, const BigNumber &rhs) {
    BigNumber result = BigNumber("0");
    BigNumber factor1;
    BigNumber factor2;
    BigNumber temp;
    bool sign = false;


    if(lhs.number.size() >= rhs.number.size()) {
        factor1 = lhs;
        factor2 = rhs;
    } else {
        factor1 = rhs;
        factor2 = lhs;
    }

    if((factor1 < BigNumber("0") and factor2 >= BigNumber("0")) or
                                                    (factor1 >= BigNumber("0") and factor2 < BigNumber("0"))) {
        factor1 = factor1.abs();
        factor2 = factor2.abs();
        sign = true;
    } else if(factor1 < BigNumber("0") and factor2 < BigNumber("0")) {
        factor1 = factor1.abs();
        factor2 = factor2.abs();
    }

    for(int i = 0; i < factor2.number.size(); ++i) {
        temp = factor1;
        for(int j = 0; j < factor1.number.size(); ++j) {
            temp.number.at(j) = factor1.number.at(j) * factor2.number.at(i);
        }

        for(int k = 0; k < temp.number.size(); ++k) {
            if(temp.number.at(k) >= 10) {
                if(k < temp.number.size() - 1) {
                    temp.number.at(k + 1) += temp.number.at(k) / 10;
                } else {
                    temp.number.push_back(temp.number.at(k) / 10);
                }
                temp.number.at(k) %= 10;
            }
        }

        temp.number.insert(temp.number.begin(), i, 0);
        result = result + temp;
    }


    if(sign) {
        *result.number.rbegin() *= -1;
    }

    return result;
}


bool operator>(const BigNumber &lhs, const BigNumber &rhs) {

    if(*lhs.number.rbegin() >= 0 and *rhs.number.rbegin() < 0) {
        return true;
    } else if(*lhs.number.rbegin() < 0 and *rhs.number.rbegin() >= 0) {
        return false;
    } else if(*lhs.number.rbegin() < 0 and *rhs.number.rbegin() < 0) {
        return (lhs.abs() < rhs.abs());
    }
    if(lhs.number.size() >  rhs.number.size()) {
        return true;
    } else if(lhs.number.size() ==  rhs.number.size()) {
        for(auto it1 = lhs.number.rbegin(), it2 = rhs.number.rbegin();
                    it1 != lhs.number.rend() ; ++it1, ++it2) {
            if(*it1 > *it2) {
                return true;
            } else if(*it1 < *it2) {
                return false;
            }
        }
    }

    return false;
}


bool operator<(const BigNumber &lhs, const BigNumber &rhs) {

    if(*lhs.number.rbegin() < 0 and *rhs.number.rbegin() >= 0) {
        return true;
    } else if(*lhs.number.rbegin() >= 0 and *rhs.number.rbegin() < 0) {
        return false;
    } else if(*lhs.number.rbegin() < 0 and *rhs.number.rbegin() < 0) {
        return (lhs.abs() > rhs.abs());
    }
    if(lhs.number.size() <  rhs.number.size()) {
        return true;
    } else if(lhs.number.size() ==  rhs.number.size()) {
        for(auto it1 = lhs.number.rbegin(), it2 = rhs.number.rbegin();
            it1 != lhs.number.rend(); ++it1, ++it2) {
            if(*it1 < *it2) {
                return true;
            } else if(*it1 > *it2) {
                return false;
            }
        }
    }

    return false;
}


bool operator==(const BigNumber &lhs, const BigNumber &rhs) {
    if(lhs.number.size() ==  rhs.number.size()) {
        for(auto it1 = lhs.number.rbegin(), it2 = rhs.number.rbegin(); it1 != lhs.number.rend(); ++it1, ++it2) {
            if(*it1 > *it2 or *it1 < *it2) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}


bool operator>=(const BigNumber &lhs, const BigNumber &rhs) {
    return (lhs > rhs) or (lhs == rhs);
}


bool operator<=(const BigNumber &lhs, const BigNumber &rhs) {
    return (lhs < rhs) or (lhs == rhs);
}

BigNumber BigNumber::abs() const {
    BigNumber result = *this;
    if(*result.number.rbegin() < 0) {
        *result.number.rbegin() *= -1;
    }

    return result;
}


int BigNumber::reduction() {
    bool sign;

    return -1;
}
