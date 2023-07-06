#include <stdio.h>

int main()
{

  unsigned char num1[] = {// A C2FFCD12
                          0x12,
                          0xCD,
                          0xFF,
                          0xC2};
  unsigned char num2[] = {// B C1BB0A01
                          0x01,
                          0x0A,
                          0xBB,
                          0xC1};

  unsigned char collection[8] = {// C 00 00 00 00  00 00 00 00
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00};
  unsigned char *c;
  c = collection;
  for (int i = 0; i < sizeof(num2); i++)
  { // num 2 loop
    for (int j = 0; j < sizeof(num1); j++)
    { // num 1 loop

      printf("%d ", &c[i + j]);
      // printf("%02X", x);
      printf("%d\n", &c[i + j + 1]);
    }
  }
  printf("%d", &collection[0]);
}