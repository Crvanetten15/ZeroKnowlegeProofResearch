#include <stdio.h>
#include "size.h"

int trueSizeOf(unsigned char *value)
{ 
  return sizeof(value) / sizeof(value[0]);
}
