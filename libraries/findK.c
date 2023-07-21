#include <stdio.h>
#include "findK.h"

int FindHexK(unsigned char *value)
{

  int end;
  end = (sizeof(value) / sizeof(value[0])) - 1;
  unsigned char val = 0b1;
  // printf("%02X", value[end]);
  int k = 0;

  unsigned char top = (value[end] >> 4);

  while (val < value[end])
  {
    if (val == 0x80)
    {
      // printf("Overflow : ");
      val = 0x00;
      break;
    }
    // printf("%02X ", value[end]);
    val <<= 1;
    // printf("%02X\n", val);
    k++;
  }

  if (val == 0x00)
  {
    k = 8;
  }
  int size = ((sizeof(value) / sizeof(value[0])) * 7) - 7;
  k += size;
  // printf("%d", k);
  return k;
}