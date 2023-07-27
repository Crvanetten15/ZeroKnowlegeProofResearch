#include <stdio.h>
#include "multiplier.h"
#include "findK.h"
#include "shifting.h"
#include "subtraction.h"

#define SIZE 8

int main(int argc, char *argv[])
{
    unsigned char a[] = {
        0x83,
        0x23,
        0x2C,
        0x6F,
        0x83,
        0x23,
        0x2C,
        0x6F};

    unsigned char b[] = {
        0x83,
        0x23,
        0x2C,
        0x6F,
        0xFB,
        0x08,
        0xFB,
        0x08};

    unsigned char n[] = {
        0x83,
        0x23,
        0x2C,
        0x6F,
        0xFB};

    unsigned char *c = hex_multiplier(a, b, SIZE, SIZE);

    int k = FindHexK(n);


    // Hex bit is failing
    hexBitShift(c, 8);
    for (int i = 0; i < (SIZE * 2); i++)
    {
        printf("%02X ", c[i]);
    }
}
