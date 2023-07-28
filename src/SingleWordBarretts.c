#include <stdio.h>

// Needed for Debugging
// void printInBin(unsigned char i)
// {
//     while (i)
//     {
//         if (i & 1)
//             printf("1");
//         else
//             printf("0");

//         i >>= 1;
//     }
//     printf("\n");
// }

unsigned char reduct(unsigned char a, unsigned char n)
{
    unsigned char x = 0x01;
    unsigned char k = 0x01;

    while (x < n)
    {
        x <<= 1;
        k++;
    }
    unsigned char m = 0x01; // This is due to the next highest power of two will never be more than 1.999999 times larger and we floor it
    // m == 1 in this example
    unsigned char q = (a * m) >> k;
    a -= q * n;

    // Researching I saw reports of it being between [0 - 3n) instead of [0-2n) (while loop fixes it)
    while (a >= n)
    {
        a -= n;
    }
    return a;
}

int main(int argc, char *argv[])
{

    unsigned char a = 0xFe;
    unsigned char n = 0x03;

    printf("Barretts Reduction : \n%02X", reduct(a, n));
    printf("\nMod Operator : \n%02X", a % n);
}
