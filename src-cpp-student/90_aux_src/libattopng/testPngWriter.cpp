// Author: Carsten Link 2019
// see libattopng's LICENSE

#include "pngWriter.hpp"




int main(){
  PngWriter png(600,400);
  png.setPixel(0,0, {255,0,0});
  png.setPixel(0,1, {0,255,0});
  png.setPixel(0,2, {0,0,255});
  png.setPixel(1,1, {255,255,255});
  ColorRgb col = png.getPixel(1,1);
  png.setPixel(2,2, col);
  col.red -= 100;
  col.green -= 100;
  col.blue -= 100;
  png.setPixel(3,3, col);
  png.write("testPngWriter.png");
  return 0;
}
