#include <stdio.h>
#include "multiplier.h"

void hex_subtract()
{
}

void hex_bitshift()
{
}

void printInBin(unsigned char i)
{
    while (i)
    {
        if (i & 1)
            printf("1");
        else
            printf("0");

        i >>= 1;
    }
    printf("\n");
}
unsigned char reduct(unsigned char a, unsigned char m, unsigned char n)
{
    unsigned char k = 0x03;
    // printInBin(k);

    unsigned char q = (a * m) >> k;
    // printInBin(a * m);
    // printInBin(q);

    unsigned char i = q;
    printInBin(q * n);
    printf(" %d\n", q * n);
    printInBin(a);
    printf(" %d\n", a);
    a -= q * n;

    // Since C is now with 2n, we check for if it is larger than n, if so subtract n once
    if (a >= n)
    {
        a -= n;
        printInBin(a);
    }
    return a;
}

int main(int argc, char *argv[])
{

    unsigned char a = 0x09;
    unsigned char n = 0x04;
    unsigned char m = 0x08;

    printf("\n%02X", reduct(a, m, n));
    printf("\n%02X", a % n);

    // 1 / n == m / 2 ^k
    // c = a * b mod n

    // c = q * n + r (with r being our answer)

    // r = c - q * n

    // q = c * m / 2^k
}