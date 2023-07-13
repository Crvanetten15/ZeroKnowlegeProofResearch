#include <stdio.h>
#include <stdlib.h>

unsigned char *perform_modulus(const unsigned char *num1, size_t size1, const unsigned char *num2, size_t size2, size_t *resultSize)
{
  // Create a result array with maximum size
  unsigned char *result = (unsigned char *)malloc((size1 + 1) * sizeof(unsigned char));

  // Initialize result array with zeros
  for (size_t i = 0; i < size1 + 1; ++i)
  {
    result[i] = 0;
  }

  // Perform modulus operation
  for (size_t i = 0; i < size1; ++i)
  {
    unsigned char current_digit = num1[i] + result[i] * 10;
    result[i] = current_digit / num2[0];
    unsigned char remainder = current_digit % num2[0];

    // Carry over the remainder to the next digit
    if (i < size1 - 1)
    {
      result[i + 1] += remainder * 10;
    }
  }

  // Find the actual size of the result
  *resultSize = size1;
  while (*resultSize > 0 && result[*resultSize - 1] == 0)
  {
    --(*resultSize);
  }

  // Reallocate the result array with the actual size
  result = (unsigned char *)realloc(result, *resultSize * sizeof(unsigned char));

  return result;
}

int main()
{
  unsigned char num1[] = {1, 2, 3, 4, 5, 6};
  size_t size1 = sizeof(num1) / sizeof(num1[0]);

  unsigned char num2[] = {7, 8, 9};
  size_t size2 = sizeof(num2) / sizeof(num2[0]);

  size_t resultSize = 0;
  unsigned char *modulusResult = perform_modulus(num1, size1, num2, size2, &resultSize);

  // Print the modulus result
  for (size_t i = 0; i < resultSize; ++i)
  {
    printf("%hhu ", modulusResult[i]);
  }

  // Clean up memory
  free(modulusResult);

  return 0;
}
