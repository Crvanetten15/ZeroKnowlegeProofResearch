#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "multiplier.h"

// Multiply and bit-shift the result to fit in a temporary array
void multiHex(unsigned char a, unsigned char b, unsigned char *t)
{
  unsigned int multiply_result = a * b;

  t[0] = multiply_result & 0xFF;
  t[1] = (multiply_result >> 8) & 0xFF;
}

// Add each pair of hex values and handle carry values
void addHex(unsigned char t, unsigned char *c, unsigned char *carry)
{
  unsigned char total = t + *c + *carry;
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

unsigned char *hex_multiplier(unsigned char *array1, unsigned char *array2, int size1, int size2)
{
  unsigned char *collection = (unsigned char *)malloc((size1 + size2) * sizeof(unsigned char));
  if (collection == NULL)
  {
    printf("Memory allocation failed!");
    return NULL;
  }
  else
  {
    for (int k = 0; k < size1 + size2; k++)
    {
      collection[k] = 0x00;
    }
  }

  unsigned char temp[2] = {0x00, 0x00};

  unsigned char *c = collection;
  unsigned char *t = temp;
  unsigned char carry = 0x00;
  unsigned char *x = &carry;

  // Nested loops used to navigate the two arrays
  for (int i = 0; i < size2; i++)
  { // num2 loop
    for (int j = 0; j < size1; j++)
    { // num1 loop
      multiHex(array1[j], array2[i], t);
      addHex(t[0], &c[i + j], x);
      addHex(t[1], &c[i + j + 1], x);
    }
  }

  return collection;
}
