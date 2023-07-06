#include <stdio.h>
#include "multiplier.h"

int main (int argc, char *argv[]) {

    unsigned char a[] = { // CD12
        0x12,
        0xCD};
    unsigned char b[] = { // 1A01
        0x01,
        0x1A};
    int sizeA = sizeof(a) / sizeof(a[0]); // needed for my multiplier
    int sizeB = sizeof(b) / sizeof(b[0]); // needed for my multiplier


    // 1 / n == m /2 ^k
    // c = a * b mod n 
    

    // c = q * n + r (with r being our answer)

    // r = c - q * n

    // q = c * m / 2^k

  
} 