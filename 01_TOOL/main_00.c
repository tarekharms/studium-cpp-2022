
int line(int x){
  return x * 4 - 5;
}

int main(){
  int y = 0;
  int x = 0;
  int numZeros = 0;
  while ( x < 10 ){
    y = line(x);
    // TODO: print values
    x++;
  } 
  return 0;
}
