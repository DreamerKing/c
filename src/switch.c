#include <stdio.h>
#include <stdlib.h>

int main() {
  int count = 3;
  switch (count) {
  default:
    puts("++++====++++");
  case 4:
    puts("++++");
  case 3:
    puts("+++");
  case 2:
    puts("++");
  case 1:
    puts("+");
  case 0:;
  }
  return EXIT_SUCCESS;
}