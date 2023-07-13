#include <stdio.h>

void subtractBigHexNum(unsigned char *a, unsigned char *b, unsigned char *result, int size)
{
  unsigned char carry = 0;

  for (int i = size - 1; i >= 0; i--)
  {
    unsigned char digit = a[i] - b[i] - carry;

    if (digit > a[i])
    {
      digit += 0x100;
      carry = 0x01;
    }
    else
    {
      carry = 0x00;
    }

    result[i] = digit;
  }
}

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