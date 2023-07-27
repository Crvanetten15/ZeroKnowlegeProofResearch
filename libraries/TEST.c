#include <stdio.h>
#include "shifting.h"
#include "size.h"

int main()
{
  unsigned char value[4] = {
      0x12,
      0x13,
      0xCD,
      0x2E};
  printf("%d", trueSizeOf(value));
}