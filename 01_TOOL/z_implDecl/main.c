#include <stdio.h>

double twice(double);

int main(){
  int i = 7;
  printf("twice(%d)=%d\n",i,(int)twice(i));
  return 0;
}
