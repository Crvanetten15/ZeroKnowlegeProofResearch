#include <stdio.h>
#include "shifting.h"

void hexBitShift(unsigned char *value, int k, int size)
{
  unsigned char mask_m[8] = {
      0x1,
      0x3,
      0x7,
      0xF,
      0x1F,
      0x3F,
      0x7F};

  // printf("%d here", k);

  for (int i = 0; i < size; i++)
  {
    // printf("V = %02X\n", value[i]);
    value[i] >>= k;
    // printf("0 = %02X\n", value[i]);
    if (i < size - 1)
    {
      value[i] = (((value[i + 1] & mask_m[k]) << 8 - k) | value[i]);
    }
  }
}

// int main()
// {
//   unsigned char value[4] = {
//       0x12,
//       0x13,
//       0xCD,
//       0x2E};

//   hexBitShift(value, 4);

//   for (int i = 0; i < 4; i++)
//   {
//     printf("%02X", value[i]);
//   }
// }