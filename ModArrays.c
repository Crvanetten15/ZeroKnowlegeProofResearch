#include <stdio.h>
int main()
{
  unsigned char num1[] = {
      0x13,
      0x0B};
  unsigned char num2[] = {
      0x03,
      0x0A};

  for (int i = 0; i < 2; i++)
  {
    num1[i] %= num2[i];
  }
  printf("%d %d = %d\n", 0xb13, 0xa03, (0xb13 % 0xa03));
  printf("%02X %02X", num1[0], num1[1]);
}