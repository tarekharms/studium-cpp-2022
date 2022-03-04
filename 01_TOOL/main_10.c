#define SLOPE 7
#define OFFSET -3
#define MIN 0
#define MAX 20 

int line(int x){
  return x * SLOPE + OFFSET;
}

int main(){
  int y = 0;
  int x = MIN;
  while (x<MAX){
    y = line(x);
    // TODO: print values
    x++;
  } 
  return 0;
}
