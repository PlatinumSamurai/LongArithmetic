#include "BigNumber.h"

BigNumber::BigNumber(const std::string &str) {
    number.reserve(str.size());
    for(const char item : str) {
        if(std::isdigit(item)) {
            number.push_back(item - '0');
        }
    }
}


std::ostream &operator<<(std::ostream &out, const BigNumber &number) {
    for(const short item : number.number) {
        out << item;
    }

    return out;
}
