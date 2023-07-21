#include <stdio.h>
#include "multiplier.h"
#include "findK.h"
#include "shifting.h"
#include "subtraction.h"

unsigned char AA = {
    0x83,
    0x23,
    0x2C,
    0x6F,
    0xFB,
    0x08,
    0xB1,
    0x4B,
    0x0A,
    0x98,
    0x15,
    0xB5,
    0xEC,
    0xD6,
    0xCE
};

unsigned char BB = {
    0x83,
    0x23,
    0x2C,
    0x6F,
    0xFB,
    0x08,
    0xB1,
    0x4B,
    0x0A,
    0x98,
    0x15,
    0xB5,
    0xEC,
    0xD6,
    0xCE
};

unsigned char reduct(unsigned char *a, unsigned char *b, unsigned char * n)
{
    int size1 = sizeof(a) / sizeof(a[0]);
    int size2 = sizeof(b) / sizeof(b[0]);
    unsigned char * total = hex_multiplier(a, b, size1, size2); 
    unsigned char A[128];
    int k = FindHexK(total);
    memcpy(A, total, sizeof(total) / sizeof(total[0]));
    unsigned char m = 0x01; // This is due to the next highest power of two will never be more than 1.999999 times larger and we floor it
    // m == 1 in this example
    hexBitShift(total, k);
    unsigned char * val = hex_multiplier(total, n, sizeof(total) / sizeof(total[0]), sizeof(a) / sizeof(a[0]));

    A -= total * n;

    // Researching I saw reports of it being between [0 - 3n) instead of [0-2n) (while loop fixes it)
    while (a >= n)
    {
        a -= n;
    }
    return a;
}

int main(int argc, char *argv[])
{

    reduct(AA, BB, 8);
}
