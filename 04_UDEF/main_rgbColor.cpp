#include "rgbColor.hpp"
#include "println.hpp"


void foobar(double d){
  println("foobar(double d), d = ", d);
}

int main(){
  RgbColor pureBlue(0xff);
  println("pureBlue = ", pureBlue);
  
  RgbColor pureRed(0xff0000);
  println("pureRed = ", pureRed);
  
  RgbColor grey(127,127,127); // red, green, blue
  println("grey = ", grey);
  
  RgbColor mix1 = pureBlue + pureRed;
  println("mix1 = ", mix1);

  RgbColor mix2 = pureRed + pureRed;
  println("mix2 = ", mix2);

  unsigned int ui_mix1 = static_cast<unsigned int>(mix1);
  println("ui_mix1 = ", ui_mix1);
  
  RgbColor nothing(0x010101);
  println("nothing = ", nothing);
  ++nothing;
  println("nothing = ", nothing);
  
  RgbColor otw(0x123456);
  println("otw.luminosity() = ", static_cast<unsigned int>(otw.luminosity()));
#ifdef LEVEL_C
  println("otw.negated() = ", otw.negated());
  foobar(static_cast<double>(otw));
#endif
  return 0;
}

