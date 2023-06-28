#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8;

// Mulitplying and bit shifting answer to fit in temporary array
void multiHex(unsigned char a, unsigned char b, unsigned char *t)
{
  unsigned int multiply_result = a * b;

  t[0] = multiply_result & 0xFF;
  t[1] = (multiply_result >> 8) & 0xFF;

  return 0;
}

// Adding each set of hex pairs and dealing with the carry values
int addHex(unsigned char t, unsigned char *c, unsigned char *carry)
{
  // printf("%02X - \n", *c);
  unsigned char total = t + *c + *carry;
  // printf("%02X - \n", total);
  if (total < t || total < *c)
  {
    *carry = 0x01;
  }
  else
  {
    *carry = 0x00;
  }
  *c = total;
}

int main(int argc, char *argv[])
{
  unsigned char num1[] = {// A C2FFCD12
                          0x12,
                          0xCD};
  unsigned char num2[] = {// B C1BB0A01
                          0x01,
                          0x0A};
  unsigned char collection[4] = {// C 00 00 00 00  00 00 00 00
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00};

  unsigned char temp[2] = {0x00, 0x00};

  unsigned char *c;
  c = collection;

  unsigned char *t;
  t = temp;

  unsigned char carry = 0x00;
  unsigned char *x;
  x = carry;

  for (int i = 0; i < sizeof(num2); i++)
  { // num 2 loop
    for (int j = 0; j < sizeof(num1); j++)
    { // num 1 loop
      multiHex(num1[j], num2[i], t);
      addHex(t[0], &c[i + j], &x);
      addHex(t[1], &c[i + j + 1], &x);
    }
  }

  for (int x = 0; x < sizeof(collection); x++)
  {
    printf("%02X ", collection[x]);
  }

  return 0;
}
