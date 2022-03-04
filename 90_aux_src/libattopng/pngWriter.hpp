// Author: Carsten Link 2019
// see libattopng's LICENSE

#ifndef PNGWRITER_HPP
#define PNGWRITER_HPP
#include <string>

extern "C" {
#include "libattopng.h"
}


//TODO: use https://en.cppreference.com/w/cpp/language/structured_binding
struct ColorRgb {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  ColorRgb(unsigned char red=0, unsigned char green=0, unsigned char blue=0);
  ColorRgb(const ColorRgb&);
  ColorRgb& operator= (ColorRgb& other);
};

bool operator == (const ColorRgb& left, const ColorRgb& right);
std::string as_string(ColorRgb);

class PngWriter {
  libattopng_t *pngHandle;
public:
  PngWriter(unsigned int widht, unsigned int heigt);
  PngWriter(const PngWriter&) = delete;
  ~PngWriter();
  void setPixel(unsigned int x, unsigned int y, ColorRgb color);
  ColorRgb getPixel(unsigned int x, unsigned int y);
  void write(std::string fileName);
};


#endif

