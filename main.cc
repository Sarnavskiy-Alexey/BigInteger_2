#include "BigInteger.h"

int main() {
    BigInteger::BigInteger a = BigInteger::BigInteger(89645213);
    BigInteger::BigInteger b = BigInteger::BigInteger(78956423);

    BigInteger::BigInteger c = a * b;

    c.print();

    return 0;
}
