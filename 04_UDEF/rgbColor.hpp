// file: FixedPoint.hpp
#ifndef RGBCOLOR_HPP
#define RGBCOLOR_HPP

#include <string>

struct RgbColor {
  unsigned int m_red;
  unsigned int m_green;
  unsigned int m_blue;

public:
  
  RgbColor();
  explicit RgbColor(uint32_t red, uint32_t green, uint32_t blue);
  explicit RgbColor(uint32_t rgbVal);
  operator unsigned int();
  explicit operator unsigned int*();

  RgbColor& operator++();
  RgbColor operator++(int);

  uint8_t red()   const ;
  uint8_t green() const ;
  uint8_t blue()  const ;
  
  RgbColor& operator+=(const RgbColor&);

  int luminosity();

};

RgbColor operator+ (RgbColor left, RgbColor right);
std::string as_string(RgbColor);  // for println()

#endif

