#include "BigNumber.h"


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


BigNumber::BigNumber(const long long int &num) {
    BigNumber temp = to_BigNumber(num);

    *this = temp;
}


BigNumber::BigNumber(const std::vector<int8_t> &vec) {
    number = vec;
}


BigNumber BigNumber::operator+(const BigNumber &rhs) const {
    BigNumber result;
    BigNumber term;
    bool sign = false;


    if(this->number.size() >= rhs.number.size()) {
        result = *this;
        term = rhs;
    } else {
        result = rhs;
        term = *this;
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


BigNumber BigNumber::operator-(const BigNumber &rhs) {
    BigNumber result;
    BigNumber subtrahend;
    bool sign = false;
    bool permutation = false;


    if(this->number.size() >= rhs.number.size()) {
        result = *this;
        subtrahend = rhs;
    } else {
        result = rhs;
        subtrahend = *this;
        permutation = true;
    }

    if(result >= BigNumber("0") and subtrahend < BigNumber("0")) {
        result = result + subtrahend.abs();
        if(permutation) {
            return result * BigNumber("-1");
        }
        return result;
    } else if(result < BigNumber("0") and subtrahend >= BigNumber("0")) {
        result = result.abs() + subtrahend.abs();
        sign = true;
        if(permutation != sign) {
            return result * BigNumber("-1");
        }
        return result;
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

    result.reduction();

    if(sign != permutation) {
        result = result * BigNumber("-1");
    }

    return result;
}


BigNumber BigNumber::operator*(const BigNumber &rhs) {
    BigNumber result = BigNumber("0");
    BigNumber factor1;
    BigNumber factor2;
    BigNumber temp;
    bool sign = false;


    if(this->number.size() >= rhs.number.size()) {
        factor1 = *this;
        factor2 = rhs;
    } else {
        factor1 = rhs;
        factor2 = *this;
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

    result.reduction();
    if(sign) {
        *result.number.rbegin() *= -1;
    }

    return result;
}


BigNumber BigNumber::operator/(const BigNumber &rhs) const {
    BigNumber dividend = *this;
    BigNumber divisor = rhs;
    BigNumber result;
    BigNumber temp;
    BigNumber remainder;
    unsigned long long int step = 0;
    bool sign = false;

    if(divisor == BigNumber("0")) {
        throw std::domain_error("Division by zero");
    }

    if(*this >= BigNumber("0") and rhs < BigNumber("0")) {
        divisor = divisor.abs();
        sign = true;
    } else if(*this < BigNumber("0") and rhs >= BigNumber("0")) {
        dividend = dividend.abs();
        sign = true;
    }  else if(*this < BigNumber("0") and rhs < BigNumber("0")) {
        dividend = dividend.abs();
        divisor = divisor.abs();
    }

    while(dividend >= divisor) {
        if(remainder == BigNumber("0")) {
            step = 1;
        } else {
            step = remainder.number.size() + 1;
        }
        for(auto i = step; i <= dividend.number.size(); ++i) {
            temp.number.clear();
            std::copy(dividend.number.end() - i, dividend.number.end(), std::back_inserter(temp.number));
            temp.reduction();
            if(temp >= divisor) {
                break;
            } else {
                result.number.insert(result.number.begin(), 0);
            }
        }
        if(temp == 0) {
            break;
        }

        for(int i = 1; i <= 9; ++i) {
            BigNumber tempTemp = divisor * BigNumber(std::to_string(i));
            if(tempTemp > temp) {
                result.number.insert(result.number.begin(), i - 1);
                // TODO any possible optimization?
                for(long long int j = 0; j < temp.number.size(); ++j) {
                    dividend.number.pop_back();
                }
                remainder = temp - divisor * BigNumber(std::to_string(i - 1));
                if(remainder > BigNumber("0")) {
                    for(const auto &item : remainder.number) {
                        dividend.number.push_back(item);
                    }
                } else if(dividend < divisor) {
                    result.number.insert(result.number.begin(), dividend.number.size(), 0);
                }
                break;
            }
        }
    }

    result.reduction();
    if(sign) {
        result = result * BigNumber("-1");
    }

    return result;
}


BigNumber BigNumber::operator%(const BigNumber &rhs) const {
    BigNumber dividend = *this;
    BigNumber divisor = rhs;
    BigNumber temp;
    BigNumber remainder;
    unsigned long long int step = 0;
    bool sign = false;

    if(divisor == BigNumber("0")) {
        throw std::domain_error("Division by zero");
    }

    if(*this >= BigNumber("0") and rhs < BigNumber("0")) {
        divisor = divisor.abs();
    } else if(*this < BigNumber("0") and rhs >= BigNumber("0")) {
        dividend = dividend.abs();
        sign = true;
    }  else if(*this < BigNumber("0") and rhs < BigNumber("0")) {
        dividend = dividend.abs();
        divisor = divisor.abs();
        sign = true;
    }

    while(dividend >= divisor) {
        if(remainder == BigNumber("0")) {
            step = 1;
        } else {
            step = remainder.number.size() + 1;
        }
        for(auto i = step; i <= dividend.number.size(); ++i) {
            temp.number.clear();
            std::copy(dividend.number.end() - i, dividend.number.end(), std::back_inserter(temp.number));
            temp.reduction();
            if(temp >= divisor) {
                break;
            }
        }
        if(temp == 0) {
            break;
        }

        for(int i = 1; i <= 9; ++i) {
            BigNumber tempTemp = divisor * BigNumber(std::to_string(i));
            if(tempTemp > temp) {
                // TODO any possible optimization?
                for(long long int j = 0; j < temp.number.size(); ++j) {
                    dividend.number.pop_back();
                }
                remainder = temp - divisor * BigNumber(std::to_string(i - 1));
                if(remainder > BigNumber("0")) {
                    for(const auto &item : remainder.number) {
                        dividend.number.push_back(item);
                    }
                }
                break;
            }
        }
    }

    dividend.number.push_back(0);
    dividend.reduction();
    if(sign) {
        dividend = dividend * BigNumber("-1");
    }

    return dividend;
}


bool BigNumber::operator>(const BigNumber &rhs) const {
    if(*this->number.rbegin() >= 0 and *rhs.number.rbegin() < 0) {
        return true;
    } else if(*this->number.rbegin() < 0 and *rhs.number.rbegin() >= 0) {
        return false;
    } else if(*this->number.rbegin() < 0 and *rhs.number.rbegin() < 0) {
        return (this->abs() < rhs.abs());
    }
    if(this->number.size() > rhs.number.size()) {
        return true;
    } else if(this->number.size() ==  rhs.number.size()) {
        for(auto it1 = this->number.rbegin(), it2 = rhs.number.rbegin();
                    it1 != this->number.rend() ; ++it1, ++it2) {
            if(*it1 > *it2) {
                return true;
            } else if(*it1 < *it2) {
                return false;
            }
        }
    }

    return false;
}


bool BigNumber::operator<(const BigNumber &rhs) const {
    return !(*this > rhs) and (*this != rhs);
}


bool BigNumber::operator==(const BigNumber &rhs) const {
    if(this->number.size() ==  rhs.number.size()) {
        for(auto it1 = this->number.crbegin(), it2 = rhs.number.rbegin(); it1 != this->number.crend(); ++it1, ++it2) {
            if(*it1 > *it2 or *it1 < *it2) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}


bool BigNumber::operator>=(const BigNumber &rhs) const {
    return (*this > rhs) or (*this == rhs);
}


bool BigNumber::operator<=(const BigNumber &rhs) const {
    return (*this < rhs) or (*this == rhs);
}


bool BigNumber::operator!=(const BigNumber &rhs) const {
    return !(*this == rhs);
}


std::ostream &operator<<(std::ostream &out, const BigNumber &number) {
    for(auto it = number.number.rbegin(); it != number.number.rend(); ++it) {
        out << short(*it);
    }

    return out;
}


BigNumber BigNumber::abs() const {
    BigNumber result = *this;
    if(*result.number.rbegin() < 0) {
        *result.number.rbegin() *= -1;
    }

    return result;
}


int BigNumber::reduction() {
    auto it = this->number.rbegin();

    while(*it == 0 and this->number.size() > 1) {
        this->number.pop_back();
        it = this->number.rbegin();
    }

    return 0;
}

BigNumber BigNumber::operator+=(const BigNumber &rhs) {
    *this = *this + rhs;

    return *this;
}

BigNumber BigNumber::operator-=(const BigNumber &rhs) {
    *this = *this - rhs;

    return *this;
}


BigNumber BigNumber::operator*=(const BigNumber &rhs) {
    *this = *this * rhs;

    return *this;
}


BigNumber BigNumber::operator/=(const BigNumber &rhs) {
    *this = *this / rhs;

    return *this;
}


BigNumber BigNumber::operator%=(const BigNumber &rhs) {
    *this = *this % rhs;

    return *this;
}

BigNumber BigNumber::operator++() {
    *this = *this + 1;

    return *this;
}


const BigNumber BigNumber::operator++(int notused) {
    const BigNumber temp = *this;

    *this += 1;

    return temp;
}

BigNumber BigNumber::operator--() {
    *this = *this - BigNumber(1);

    return *this;
}

const BigNumber BigNumber::operator--(int notused) {
    const BigNumber temp = *this;

    *this -= 1;

    return temp;
}
