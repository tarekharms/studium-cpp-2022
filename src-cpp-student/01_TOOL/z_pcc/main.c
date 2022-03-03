#include <stdio.h>

int global = 8150;

int sum(int a, int b){
  int result = 451;
  result = a + b;
  return result;
}
 

int main(int argc, char **argv)
{
  int local=4711;
  printf("Hello, world!\nglobal=%d local=%d\n", global, local);
  local = sum(global, local);
  return local;
}
