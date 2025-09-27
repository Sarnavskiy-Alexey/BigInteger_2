#pragma once

#include <vector>
#include <utility>

namespace BigInteger {
    typedef char T_DIGIT;
    typedef char T_ADDABLE;
    typedef std::vector<T_DIGIT> T_NUMBER;
    typedef std::pair<T_DIGIT, T_ADDABLE> T_PLUSED;
    typedef std::pair<T_NUMBER, T_ADDABLE> T_MULTED;

    class BigInteger {
        private:
            T_NUMBER m_number;

            BigInteger plus(const BigInteger &other);
            void plus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result);
            void plus_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            BigInteger mult(const BigInteger &other);
            void mult_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const;
            void mult_line(const T_NUMBER &a, T_DIGIT b, T_MULTED &result) const;
        public:
            BigInteger() = default;
            BigInteger(int number);
            BigInteger(T_NUMBER number);
            BigInteger(const BigInteger &other);

            BigInteger operator+(const BigInteger &other);
            BigInteger operator*(const BigInteger &other);

            void print() const;
    };
} // namespace BigInteger
