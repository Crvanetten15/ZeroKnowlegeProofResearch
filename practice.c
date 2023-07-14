#include <stdio.h>
#include "subtraction.h"

int main()
{
  unsigned char num1[] = {
      0x12,
      0xCD};
  unsigned char num2[] = {
      0x01,
      0x0A};
  unsigned char result[2];

  int size = sizeof(num1) / sizeof(num1[0]);

  subtractBigHexNum(num1, num2, result, size);
  for (int i = 0; i < 2; i++)
  {
    printf("%02X ", result[i]);
  }

  return 0;
}