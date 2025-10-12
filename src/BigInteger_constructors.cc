#include "BigInteger.h"
#include <string>

namespace BigInteger {
    BigInteger::BigInteger(T_NUMBER number, const bool sign) {
        this->m_number = number;
        this->sign = sign;
    }

    BigInteger::BigInteger(bool number) {
        this->sign = false;
        if (number == false) this->m_number.emplace_back('0');
        else this->m_number.emplace_back('1');
    }

    BigInteger::BigInteger(char number) {
        if (number >= 0) {
            this->sign = false;
        } else {
            this->sign = true;
            number = -number;
        }
        for (auto c : std::to_string((long)number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(short number) {
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

    BigInteger::BigInteger(long number) {
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
    
    BigInteger::BigInteger(long long number) {
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

    BigInteger::BigInteger(unsigned char number) {
        this->sign = false;
        for (auto c : std::to_string((unsigned long)number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(unsigned short number) {
        this->sign = false;
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(unsigned int number) {
        this->sign = false;
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(unsigned long number) {
        this->sign = false;
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }
    
    BigInteger::BigInteger(unsigned long long number) {
        this->sign = false;
        for (auto c : std::to_string(number)) {
            this->m_number.emplace_back(c);
        }
    }

    BigInteger::BigInteger(const BigInteger &other)
    {
        this->m_number = other.m_number;
        this->sign = other.sign;
    }

    BigInteger::BigInteger(const std::string &string_number) {
        this->sign = false;
        for (size_t i = 0U; i < string_number.length(); i++) {
            if (i == 0U && string_number[i] == '-') this->sign = true;
            else this->m_number.emplace_back(string_number[i]);
        }
    }

    BigInteger::BigInteger(const char *number) {
        std::string string_number{number};
        this->sign = false;
        for (size_t i = 0U; i < string_number.length(); i++) {
            if (i == 0U && string_number[i] == '-') this->sign = true;
            else this->m_number.emplace_back(string_number[i]);
        }
    }
} // namespace BigInteger
