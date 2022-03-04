// Author: Carsten Link 2019
// see libattopng's LICENSE

#include "pngWriter.hpp"

//TODO: constexpr? inline func?
#define PNG_RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))
#define PNG_RGB(r, g, b) PNG_RGBA(r, g, b, 0xff)


bool operator == (const ColorRgb& left, const ColorRgb& right){
  return (left.red == right.red) &&
  (left.green == right.green) &&
  (left.blue == right.blue);
}

ColorRgb::ColorRgb(const ColorRgb& other){
  red = other.red;
  green = other.green;
  blue = other.blue;
}

ColorRgb::ColorRgb(unsigned char _red, unsigned char _green, unsigned char _blue){
  red = _red;
  green = _green;
  blue = _blue;
}

std::string as_string(ColorRgb col){
  std::string result;
  result += "(";
  result += std::to_string(col.red);
  result += ",";
  result += std::to_string(col.green);
  result += ",";
  result += std::to_string(col.blue);
  result += ")";
  return result;
}

ColorRgb& ColorRgb::operator= (ColorRgb& other){
  red = other.red;
  green = other.green;
  blue = other.blue;
  return *this;
}


PngWriter::PngWriter(unsigned int widht, unsigned int heigt){
  pngHandle = libattopng_new(widht, heigt, PNG_RGB);
}

PngWriter::~PngWriter(){
  libattopng_destroy(pngHandle);
}

void PngWriter::setPixel(unsigned int x, unsigned int y, ColorRgb color){
  libattopng_set_pixel(pngHandle, x, y, PNG_RGB(color.red,color.green,color.blue));
}

ColorRgb PngWriter::getPixel(unsigned int x, unsigned int y){
  uint32_t col = libattopng_get_pixel(pngHandle, x, y);
  return {static_cast<unsigned char>((col >> 16) & 0xFF),
          static_cast<unsigned char>((col >> 8) & 0xFF),
          static_cast<unsigned char>(col  & 0xFF)};
}

void PngWriter::write(std::string fileName){
  libattopng_save(pngHandle, fileName.c_str());
}

