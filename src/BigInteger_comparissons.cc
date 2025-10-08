#include "BigInteger.h"

namespace BigInteger {
    bool BigInteger::operator<(const BigInteger &other) const {
        if (this->sign && !other.sign) {
            return true;
        } else if (!this->sign && other.sign) {
            return false;
        } else if (!this->sign && !other.sign) {
            if (this->m_number.size() < other.m_number.size()) {
                return true;
            } else if (this->m_number.size() > other.m_number.size()) {
                return false;
            } else {
                for (int i = 0; i < this->m_number.size(); i++) {
                    if (this->m_number[i] < other.m_number[i]) {
                        return true;
                    } else if (this->m_number[i] > other.m_number[i]) {
                        return false;
                    }
                }
            }
        } else {
            if (this->m_number.size() > other.m_number.size()) {
                return true;
            } else if (this->m_number.size() < other.m_number.size()) {
                return false;
            } else {
                for (int i = 0; i < this->m_number.size(); i++) {
                    if (this->m_number[i] > other.m_number[i]) {
                        return true;
                    } else if (this->m_number[i] < other.m_number[i]) {
                        return false;
                    }
                }
            }
        }
        
        return false;
    }

    bool BigInteger::operator>=(const BigInteger &other) const {
        return !(*this < other);
    }

    bool BigInteger::operator>(const BigInteger &other) const {
        if (this->sign && !other.sign) {
            return true;
        } else if (!this->sign && other.sign) {
            return false;
        } else if (!this->sign && !other.sign) {
            if (this->m_number.size() > other.m_number.size()) {
                return true;
            } else if (this->m_number.size() < other.m_number.size()) {
                return false;
            } else {
                for (int i = 0; i < this->m_number.size(); i++) {
                    if (this->m_number[i] > other.m_number[i]) {
                        return true;
                    } else if (this->m_number[i] < other.m_number[i]) {
                        return false;
                    }
                }
            }
        } else {
            if (this->m_number.size() < other.m_number.size()) {
                return true;
            } else if (this->m_number.size() > other.m_number.size()) {
                return false;
            } else {
                for (int i = 0; i < this->m_number.size(); i++) {
                    if (this->m_number[i] < other.m_number[i]) {
                        return true;
                    } else if (this->m_number[i] > other.m_number[i]) {
                        return false;
                    }
                }
            }
        }

        return false;
    }

    bool BigInteger::operator<=(const BigInteger &other) const {
        return !(*this > other);
    }

    bool BigInteger::operator==(const BigInteger &other) const {
        if (this->m_number.size() != other.m_number.size()) {
            return false;
        } else {
            for (int i = 0; i < this->m_number.size(); i++) {
                if (this->m_number[i] != other.m_number[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool BigInteger::operator!=(const BigInteger &other) const {
        return ! (*this == other);
    }
}
