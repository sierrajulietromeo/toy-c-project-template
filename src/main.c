#include <stdio.h>
#include "lib.c"

int main() {

  int val1 = 40;
  int val2 = 2;

  int result1 = add(val1, val2);
  int result2 = subtract(val1, val2);
  int result3 = divide(val1,val2);

  printf("%d + %d = %d\n",val1, val2, result1);
  printf("%d - %d = %d\n", val1, val2, result2);
  printf("%d / %d = %d\n", val1, val2, result3);
  return 0;
}
