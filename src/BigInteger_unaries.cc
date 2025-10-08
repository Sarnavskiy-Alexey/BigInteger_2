#include "BigInteger.h"

namespace BigInteger {
    BigInteger BigInteger::operator-() const {
        return BigInteger{this->m_number, !this->sign};
    }
}
