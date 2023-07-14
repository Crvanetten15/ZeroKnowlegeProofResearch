#include <stdio.h>

int main()
{
  unsigned char value[4] = {
      0x12,
      0x13,
      0xCD,
      0x2E,
  };

  int end;
  end = (sizeof(value) / sizeof(value[0])) - 1;
  unsigned char val = 0x01;

  int k = 0;

  while (val < (value[end] >> 4))
  {
    val <<= 1;
  }
  
  

  return 0;
}