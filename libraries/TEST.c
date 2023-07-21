#include <stdio.h>
#include "shifting.h"

int main()
{
  unsigned char value[4] = {
      0x12,
      0x13,
      0xCD,
      0x2E};

  hexBitShift(value, 4);

  for (int i = 0; i < 4; i++)
  {
    printf("%02X", value[i]);
  }
}