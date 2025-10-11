#include "BigInteger.h"
#include <algorithm>

namespace BigInteger {
    BigInteger BigInteger::plus(const BigInteger &other) const {
        T_NUMBER result;

        this->plus_vectors(this->m_number, other.m_number, result);
        
        return BigInteger{ result, this->sign };
    }

    void BigInteger::plus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result) const {
        auto a_iter = a.end();
        auto b_iter = b.end();
        auto last_a_iter = a_iter;
        auto last_b_iter = b_iter;
        T_PLUSED plused = { 0, 0 };
        T_ADDABLE last_addable = 0;
        T_DIGIT first_digit = '0';
        T_DIGIT second_digit = '0';

        result.clear();

        while (last_a_iter != a.begin() || last_b_iter != b.begin()) {
            if (last_a_iter != a.begin()) a_iter--;
            if (last_b_iter != b.begin()) b_iter--;

            if (last_a_iter != a.begin() && last_b_iter != b.begin()) {
                first_digit = *a_iter;
                second_digit = *b_iter;
            } else if (last_a_iter != a.begin()) {
                first_digit = *a_iter;
                second_digit = '0';
            } else {
                first_digit = '0'; 
                second_digit = *b_iter;
            }
            
            this->plus_digit(first_digit + last_addable, second_digit, plused);
            result.emplace(result.begin(), plused.first);
            
            last_addable = plused.second;
            last_a_iter = a_iter;
            last_b_iter = b_iter;
        }

        if (last_addable) {
            result.emplace(result.begin(), last_addable + 0x30);
        }
    }

    void BigInteger::plus_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const {
        result.first = a + b - 0x30;
        if (result.first > '9') {
            result.first -= 0xa;
            result.second = 1;
        } else {
            result.second = 0;
        }
    }

    BigInteger BigInteger::operator+(const BigInteger &other) const {
        if (this->sign == other.sign) {
            return this->plus(other);
        } else {
            return *this - (-other);
        }
    }

    BigInteger& BigInteger::operator+=(const BigInteger &other){
        *this = *this + other;
        return *this;
    }

    void BigInteger::mult_digit(T_DIGIT a, T_DIGIT b, T_PLUSED &result) const {
        result.first = (a - 0x30) * (b - 0x30);
        result.second = result.first / 10;
        result.first -= result.second * 10;
        result.first += 0x30;
    }

    void BigInteger::mult_line(const T_NUMBER &a, T_DIGIT b, T_MULTED &result) const {
        T_PLUSED plused = { 0, 0 };
        T_PLUSED digit_plused = { 0, 0 };
        auto a_iter = a.end();
        T_ADDABLE last_addable = 0;
        result.first.clear();

        do {
            a_iter--;
            this->mult_digit(*a_iter, b, plused);
            this->plus_digit(plused.first, '0' + last_addable, digit_plused);
            result.first.emplace(result.first.begin(), digit_plused.first);
            last_addable = plused.second + digit_plused.second;
        } while (a_iter != a.begin());

        if (last_addable) {
            result.first.emplace(result.first.begin(), last_addable + 0x30);
        }
    }

    BigInteger BigInteger::mult(const BigInteger &other) const {
        T_NUMBER result_number;
        T_MULTED mult_result = { T_NUMBER{'0'}, 0 };
        T_MULTED last_mult_result;
        auto other_iter = other.m_number.end();
        size_t counter = 0;

        do {
            other_iter--;
            last_mult_result.first = result_number;
            last_mult_result.second = mult_result.second;

            this->mult_line(this->m_number, *other_iter, mult_result);
            for (size_t i = 0; i < counter; i++) {
                mult_result.first.emplace_back('0');
            }

            this->plus_vectors(mult_result.first, last_mult_result.first, result_number);
            ++counter;
        } while (other_iter != other.m_number.begin());

        this->normalize_number(result_number);

        return BigInteger{ result_number, this->sign != other.sign };
    }

    BigInteger BigInteger::operator*(const BigInteger &other) const {
        return this->mult(other);
    }

    BigInteger& BigInteger::operator*=(const BigInteger &other){
        *this = *this * other;
        return *this;
    }

    BigInteger BigInteger::minus(const BigInteger &other) const {
        T_NUMBER reducable;
        T_NUMBER subtracted;
        T_NUMBER difference;
        bool sign;
        
        if (*this >= other && !this->sign || *this <= other && this->sign) {
            sign = this->sign;
            reducable = this->m_number;
            subtracted = other.m_number;
        } else {
            sign = !this->sign;
            reducable = other.m_number;
            subtracted = this->m_number;
        }
        
        this->minus_vectors(reducable, subtracted, difference);
        this->normalize_number(difference);

        return BigInteger{ difference, sign };
    }

    void BigInteger::minus_vectors(const T_NUMBER &a, const T_NUMBER &b, T_NUMBER &result) const {
        auto a_iter = a.end();
        auto b_iter = b.end();
        auto last_a_iter = a_iter;
        auto last_b_iter = b_iter;
        T_PLUSED minused = { 0, 0 };
        T_SUBTRACTABLE last_subtractable = 0;
        T_DIGIT first_digit = '0';
        T_DIGIT second_digit = '0';

        result.clear();

        while (last_a_iter != a.begin()) {
            if (last_a_iter != a.begin()) a_iter--;
            if (last_b_iter != b.begin()) b_iter--;

            if (last_a_iter != a.begin() && last_b_iter != b.begin()) {
                first_digit = *a_iter;
                second_digit = *b_iter;
            } else if (last_a_iter != a.begin()) {
                first_digit = *a_iter;
                second_digit = '0';
            } else {
                first_digit = '0'; 
                second_digit = *b_iter;
            }
            
            this->minus_digit(first_digit - last_subtractable, second_digit, minused);
            result.emplace(result.begin(), minused.first);
            
            last_subtractable = minused.second;
            last_a_iter = a_iter;
            last_b_iter = b_iter;
        }
    }

    void BigInteger::minus_digit(T_DIGIT a, T_DIGIT b, T_MINUSED &result) const {
        result.first = a + 0x30 - b;
        if (result.first < '0') {
            result.first += 0xa;
            result.second = 1;
        } else {
            result.second = 0;
        }
    }

    BigInteger BigInteger::operator-(const BigInteger &other) const {
        if (this->sign == other.sign) {
            return this->minus(other);
        } else {
            return *this + (-other);
        }
    }

    BigInteger& BigInteger::operator-=(const BigInteger &other){
        *this = (*this) - (other);
        return *this;
    }

    BigInteger BigInteger::div(const BigInteger &divisor) const {
        bool sign = this->sign != divisor.sign;
        auto this_iter = this->m_number.begin();
        BigInteger divisable{0};
        T_NUMBER quotient;
        T_DIGIT quotient_digit = 0;

        while (this_iter < this->m_number.end()) {
            divisable.m_number.emplace_back(*this_iter);
            while ((divisor * (quotient_digit + 1)) <= divisable) {
                quotient_digit++;
            }

            quotient.emplace_back(quotient_digit + 0x30);
            divisable -= (divisor * quotient_digit);

            this_iter++;
        }

        this->normalize_number(quotient);
        return BigInteger{ quotient, sign };
    }
    
    BigInteger BigInteger::operator/(const BigInteger &other) const {
        return this->div(other);
    }

    BigInteger& BigInteger::operator/=(const BigInteger &other){
        *this = *this / other;
        return *this;
    }

    BigInteger BigInteger::remainder_div(const BigInteger &divisor) const {
        return *this - (*this / divisor) * divisor;
    }
    
    BigInteger BigInteger::operator%(const BigInteger &other) const {
        return this->remainder_div(other);
    }

    BigInteger& BigInteger::operator%=(const BigInteger &other){
        *this = *this % other;
        return *this;
    }

    BigInteger BigInteger::modulo(const BigInteger &other) const {
        BigInteger result = *this % other;
        if (result < 0) result += BigInteger{other};
        return result;
    }

    void BigInteger::normalize_number(T_NUMBER &a) const {
        while (a.size() > 1 && a[0] == '0') {
            a.erase(a.begin());
        }
    }
} // namespace BigInteger
