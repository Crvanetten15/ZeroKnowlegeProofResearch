#include <stdlib.h>
#include <stdio.h>

#define SIZE 8;
// Converter for hex to INt
int hexToInt(unsigned char num)
{
  return (num - '0' > 9) ? num - '7' : num - '0';
}

unsigned char intToHexSingle(unsigned int num)
{
  return (num >= 0 && num <= 9) ? (num + '0') : (num + '7');
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
    ret[0] = (temp >= 0 && temp <= 9) ? (temp + '0') : (temp + '7');
  }

  temp = number;
  ret[1] = (temp >= 0 && temp <= 9) ? (temp + '0') : (temp + '7');

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
  printf("%c %c\n", ret[0], ret[1]);
  // TODO : WHY DOES THIS (above) make a change to the answer
  return &ret;
}

int addHex(unsigned char temp, unsigned char *collect, unsigned int carry)
{
  int add = hexToInt(temp) + hexToInt(*collect) + carry;
  // printf("%d collected\n", hexToInt(*collect));
  // printf("%d temp\n", hexToInt(temp));
  // printf("%d total\n", add);
  int val = 0;
  if (add > 15)
  {
    add %= 16;
    val += 1;
  }
  // printf("%c hex total", intToHexSingle(add));
  *collect = intToHexSingle(add);

  if (val > 0)
  {
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  unsigned char num1[] = {'1', '2', 'A', 'B'}; // A 12AB
  unsigned char num2[] = {'5', '1', 'D', '2'}; // B

  unsigned char collection[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
  unsigned char *c;
  c = collection;
  unsigned char *t;
  // printf("%d", sizeof(num1));

  for (int i = sizeof(num2) - 1; i >= 0; i--)
  { // B
    for (int j = sizeof(num1) - 1; j >= 0; j--)
    { // A
      // printf("%d %d\n", num1[j], num2[i]);

      t = multiHex(num1[j], num2[i]);
      // TODO : THIS IS ERRORING
      int carry = addHex(t[1], &c[i + j + 1], 0);
      addHex(t[0], &c[i + j], carry);
      printf("One addtion |||  \n ");
      for (int x = 0; x < sizeof(collection); x++)
      {
        printf("%c ", collection[x]);
      }
      printf("\n");
    }
    // printf("collection ||| \n ");
    // for (int x = 0; x < sizeof(collection); x++)
    // {
    //   printf("%c ", collection[x]);
    // }
    // printf("\n");
  }

  // for (int x = 0; x < sizeof(collection); x++)
  // {
  //   printf("%c ", collection[x]);
  // }
  return 0;
}
