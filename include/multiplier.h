#ifndef MULTIPLIER_H
#define MULTIPLIER_H
// #define MY_ARRAY_SIZE 12
// extern unsigned char num1[MY_ARRAY_SIZE];
// extern unsigned char num2[MY_ARRAY_SIZE];

// unsigned char num1[MY_ARRAY_SIZE] = { 0x12, 0xCD, 0x16, 0x12, 0xCD, 0x16, 0x12, 0xCD, 0x16, 0x12, 0xCD, 0x16};
// unsigned char num2[MY_ARRAY_SIZE] = { 0x32, 0x3D, 0x36, 0x32, 0x3D, 0x36, 0x32, 0xCD, 0x16, 0x12, 0xCD, 0x16};


unsigned char *hex_multiplier(unsigned char *array1, unsigned char *array2, int size1, int size2);

#endif // MULTIPLIER_H
