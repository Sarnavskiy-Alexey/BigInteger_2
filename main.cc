#include "BigInteger.h"
#include <iostream>

int main() {
    {
        BigInteger::BigInteger a{12};
        BigInteger::BigInteger b{12};

        std::cout << (a + b).print() << std::endl;
        a += b;
        std::cout << a.print() << std::endl;
        std::cout << (a - b).print() << std::endl;
        std::cout << (a * b).print() << std::endl;
        std::cout << (a / b).print() << std::endl;
        std::cout << (a -= b).print() << std::endl;
    }
    
    {
        BigInteger::BigInteger a{21};
        BigInteger::BigInteger b{12};
        
        std::cout << (a + b).print() << std::endl;
        a += b;
        std::cout << a.print() << std::endl;
        std::cout << (a - b).print() << std::endl;
        std::cout << (a * b).print() << std::endl;
        std::cout << (a / b).print() << std::endl;
        std::cout << (a -= b).print() << std::endl;
    }

    return 0;
}
