#pragma once

#include <vector>
#include <utility>

namespace BigInteger {
    typedef char T_DIGIT;
    typedef T_DIGIT T_ADDABLE;
    typedef T_DIGIT T_SUBTRACTABLE;
    typedef std::vector<T_DIGIT> T_NUMBER;
    typedef std::pair<T_DIGIT, T_ADDABLE> T_PLUSED;
    typedef std::pair<T_NUMBER, T_ADDABLE> T_MULTED;
    typedef std::pair<T_DIGIT, T_SUBTRACTABLE> T_MINUSED;

    class BigInteger {
        private:
            T_NUMBER m_number;
            bool sign; // false = plus, true = minus

            BigInteger plus(const BigInteger &other);
            void plus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result);
            void plus_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            BigInteger mult(const BigInteger &other);
            void mult_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            void mult_line(const T_NUMBER &a, T_DIGIT b, T_MULTED &result) const;
            BigInteger minus(const BigInteger &other);
            void minus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result);
            void minus_digit(T_DIGIT a, T_DIGIT b, T_MINUSED &result) const;
        public:
            BigInteger() = default;
            BigInteger(int number);
            BigInteger(T_NUMBER number, const bool sign = false);
            BigInteger(const BigInteger &other);

            BigInteger operator+(const BigInteger &other);
            BigInteger operator*(const BigInteger &other);
            BigInteger operator-(const BigInteger &other);

            bool operator<(const BigInteger &other) const;
            bool operator>=(const BigInteger &other) const;
            bool operator>(const BigInteger &other) const;
            bool operator<=(const BigInteger &other) const;
            bool operator==(const BigInteger &other) const;
            bool operator!=(const BigInteger &other) const;

            BigInteger operator-() const;

            void print() const;
    };
} // namespace BigInteger
