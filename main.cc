#include "BigInteger.h"
#include <iostream>

int main() {
    BigInteger::BigInteger a = BigInteger::BigInteger(89645213);
    BigInteger::BigInteger b = BigInteger::BigInteger(78956423);

    BigInteger::BigInteger c = a * b;
    c.print();
    std::cout << std::endl;
    
    BigInteger::BigInteger d = a - b;
    d.print();
    std::cout << std::endl;
    
    BigInteger::BigInteger e = b - a;
    e.print();
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << (a == b);
    std::cout << (a < b);
    std::cout << (a > b);

    return 0;
}
