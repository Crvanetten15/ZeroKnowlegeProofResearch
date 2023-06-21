#include <stdlib.h>
#include <stdio.h>

#define SIZE 8;
// Converter for hex to INt
int hexToInt(unsigned char num)
{
  return (num - '0' > 9) ? num - '7' : num - '0';
}

// Converter needed for in back to hex
void intToHex(unsigned int number, unsigned char *ret)
{
  if (number == 0)
  {
    return;
  }

  int temp;
  if (number / 16 != 0)
  {
    temp = number / 16;
    number %= 16;
    if (temp >= 0 && temp <= 9)
    {
      ret[0] = temp + '0';
    }
    else
    {
      ret[0] = temp + '7';
    }
  }

  temp = number;
  if (temp >= 0 && temp <= 9)
  {
    ret[1] = temp + '0';
  }
  else
  {
    ret[1] = temp + '7';
  }

  // printf("%c%c", ret[0], ret[1]); // As of here it multiplying fine
  return;
}

// Multiplier needed get product of two hex numbers and return to temp variable
int multiHex(unsigned char top, unsigned char bottom)
{
  int valT = hexToInt(top);
  int valB = hexToInt(bottom);
  unsigned char ret[2] = {'0', '0'};
  intToHex(valT * valB, ret);

  return &ret;
}

unsigned char addHex(unsigned char *temp, unsigned char placeholder)
{

  return '1';
}

int main(int argc, char *argv[])
{
  unsigned char num1[] = {'1', '2', 'A', 'B'}; // A
  unsigned char num2[] = {'5', '1', 'D', '1'}; // B

  unsigned char c[8];
  unsigned char *t;
  // printf("%d", sizeof(num1));

  for (int i = sizeof(num2) - 1; i >= 0; i--)
  { // B
    for (int j = sizeof(num1) - 1; j >= 0; j--)
    { // A
      // printf("%d %d\n", num1[j], num2[i]);
      t = multiHex(num1[j], num2[i]);
      printf("=%d * %d=|%c%c|\n", j, i, t[0], t[1]);
    }
  }

  return 0;
}
