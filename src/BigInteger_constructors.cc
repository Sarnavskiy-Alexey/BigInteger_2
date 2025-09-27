#include "BigInteger.h"
#include <string>

namespace BigInteger {
    BigInteger::BigInteger(T_NUMBER number) {
        this->m_number = number;
    }

    BigInteger::BigInteger(int number) {
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(const BigInteger &other)
    {
        this->m_number = other.m_number;
    }
} // namespace BigInteger
