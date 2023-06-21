#include <stdlib.h>
#include <stdio.h>

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
      // printf("%d %d\n", i, j);
      c[j + i + 1] += 'A';
    }
    printf("%d %d %d %d %d %d %d %d\n", c[7], c[6], c[5], c[4], c[3], c[2], c[1], c[0]);
  }

  printf("%d %d %d %d %d %d %d %d", c[7], c[6], c[5], c[4], c[3], c[2], c[1], c[0]);

  return 0;
}
