#include "BigInteger.h"

#include <iostream>

namespace BigInteger
{
    std::string BigInteger::print() const {
        std::string result;
        if (this->sign) result += '-';
        for (auto n : this->m_number) {
            result += n;
        }
        
        return result;
    }
} // namespace BigInteger
