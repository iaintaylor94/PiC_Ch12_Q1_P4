// Program to illustrate the rotation of integers

#include <stdio.h>

// Declare Functions
unsigned int rotate (unsigned int, int);

int main(void) {

  unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

  printf ("  Rotate     BY     Equals\n");
  printf ("--------   ----   --------\n");
  printf ("%.6x   %.4d   %.6x\n", w1, 8, rotate (w1, 8));
  printf ("%.6x   %.4d   %.6x\n", w1, -16, rotate (w1, -16));
  printf ("%.6x   %.4d   %.6x\n", w2, 4, rotate (w2, 4));
  printf ("%.6x   %.4d   %.6x\n", w2, -2, rotate (w2, -2));
  printf ("%.6x   %.4d   %.6x\n", w1, 0, rotate (w1, 0));
  printf ("%.6x   %.4d   %.6x\n", w1, 44, rotate (w1, 44));
  
  return 0;
}

// Define Functions
unsigned int rotate (unsigned int value, int n) {
  unsigned int result, bits;

  if (n > 0)
    n %= 32;
  else
    n = -(-n % 32);

  if (n == 0)
    result = value;
  else if (n > 0) { // Rotate left
    bits = value >> (32 - n);
    result = value << n | bits;
  }
  else { // Rotate right
    n = -n;
    bits = value << (32 - n);
    result = value >> n | bits;
  }

  return result;
}