#include "BigInteger.h"
#include <string>

namespace BigInteger {
    BigInteger::BigInteger(T_NUMBER number, const bool sign) {
        this->m_number = number;
        this->sign = sign;
    }

    BigInteger::BigInteger(int number) {
        if (number >= 0) {
            this->sign = false;
        } else {
            this->sign = true;
            number = -number;
        }
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(const BigInteger &other)
    {
        this->m_number = other.m_number;
        this->sign = other.sign;
    }
} // namespace BigInteger
