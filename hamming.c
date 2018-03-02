#include <stdio.h>

unsigned int hamming(unsigned int x) {
  unsigned int wt = 0;

  for (int i = 0; i < (sizeof(x) * 8); i++)
    wt += ((x >> i) & 1);

  return wt;
}

int main(int argc, char *argv[]) {
  unsigned int sum = 0;
  unsigned int wt;

  for (int i = 0; i <= 0xfffffff; i++) {
    //wt = hamming(i);
    wt = __builtin_popcount(i);
    sum += wt;
    //printf("Hamming weight of %2u: %2u\n", i, wt);
  }

  printf("Sum is: %u\n", sum);

  return 0;
}