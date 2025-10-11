#pragma once

#include <vector>
#include <utility>
#include <string>

namespace BigInteger {
    typedef char T_DIGIT;
    typedef T_DIGIT T_ADDABLE;
    typedef T_DIGIT T_SUBTRACTABLE;
    typedef std::vector<T_DIGIT> T_NUMBER;
    typedef std::pair<T_DIGIT, T_ADDABLE> T_PLUSED;
    typedef std::pair<T_NUMBER, T_ADDABLE> T_MULTED;
    typedef std::pair<T_DIGIT, T_SUBTRACTABLE> T_MINUSED;
    typedef std::pair<T_NUMBER, T_SUBTRACTABLE> T_DIVED;

    class BigInteger {
        private:
            T_NUMBER m_number;
            bool sign; // false = plus, true = minus

            BigInteger plus(const BigInteger &other) const;
            void plus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result) const;
            void plus_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            BigInteger mult(const BigInteger &other) const;
            void mult_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            void mult_line(const T_NUMBER &a, T_DIGIT b, T_MULTED &result) const;
            BigInteger minus(const BigInteger &other) const;
            void minus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result) const;
            void minus_digit(T_DIGIT a, T_DIGIT b, T_MINUSED &result) const;
            BigInteger div(const BigInteger &divisor) const;

            void normalize_number(T_NUMBER &a) const;
        public:
            BigInteger() = default;
            BigInteger(int number);
            BigInteger(T_NUMBER number, const bool sign = false);
            BigInteger(const BigInteger &other);

            BigInteger operator+(const BigInteger &other) const;
            BigInteger operator*(const BigInteger &other) const;
            BigInteger operator-(const BigInteger &other) const;
            BigInteger operator/(const BigInteger &other) const;

            BigInteger& operator+=(const BigInteger &other);
            BigInteger& operator-=(const BigInteger &other);

            bool operator<(const BigInteger &other) const;
            bool operator>=(const BigInteger &other) const;
            bool operator>(const BigInteger &other) const;
            bool operator<=(const BigInteger &other) const;
            bool operator==(const BigInteger &other) const;
            bool operator!=(const BigInteger &other) const;

            BigInteger operator-() const;

            std::string print() const;
    };
} // namespace BigInteger
