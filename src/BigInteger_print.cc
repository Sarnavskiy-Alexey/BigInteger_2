#include "BigInteger.h"

#include <iostream>

namespace BigInteger
{
    void BigInteger::print() const {
        for (auto n : this->m_number) {
            std::cout << n;
        }
    }
} // namespace BigInteger
