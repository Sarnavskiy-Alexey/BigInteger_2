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
        std::cout << (a % b).print() << std::endl;
        std::cout << a.modulo(b).print() << std::endl;
        std::cout << (a -= b).print() << std::endl;
    }
    
    {
        BigInteger::BigInteger a{-21};
        BigInteger::BigInteger b{12};
        
        std::cout << (a + b).print() << std::endl;
        a += b;
        std::cout << a.print() << std::endl;
        std::cout << (a - b).print() << std::endl;
        std::cout << (a * b).print() << std::endl;
        std::cout << (a % b).print() << std::endl;
        std::cout << a.modulo(b).print() << std::endl;
        std::cout << (a -= b).print() << std::endl;
    }
    
    {
        BigInteger::BigInteger a{-21};
        short b = 12;
        
        std::cout << (a + b).print() << std::endl;
        a = b + a;
        std::cout << a.print() << std::endl;
        std::cout << (a - b).print() << std::endl;
        std::cout << (a * b).print() << std::endl;
        std::cout << (a % b).print() << std::endl;
        std::cout << a.modulo(b).print() << std::endl;
        std::cout << (a -= b).print() << std::endl;
    }

    {
        BigInteger::BigInteger a{"8386236028369189922113440947519317567908658756314394165921135120084372632403817327738382300714776112830465643750400"};
        BigInteger::BigInteger b{"8386236028369189922113440947519317567908658756314394165921135120084372632403817327738382300714776112830465643750400"};
        
        std::cout << (a + b).print() << std::endl;
        std::cout << (a * b).print() << std::endl;
    }

    return 0;
}
