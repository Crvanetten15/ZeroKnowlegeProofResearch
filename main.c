#include <stdio.h>
#include "multiplier.h"

int main()
{
  unsigned char num1[] = {
      0x12,
      0xCD,
      0x16};
  unsigned char num2[] = {
      0x01,
      0x0A};
  int size1 = sizeof(num1) / sizeof(num1[0]);
  int size2 = sizeof(num2) / sizeof(num2[0]);

  unsigned char *answer = hex_multiplier(num1, num2, size1, size2);

  printf("Hex Product: ");
  for (int i = 0; i < size1 + size2; i++)
  {
    printf("%02X ", answer[i]);
  }
  printf("\n");

  return 0;
}