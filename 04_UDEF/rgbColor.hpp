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
  explicit RgbColor(uint32_t rgbVal);

  uint8_t red()   const ;
  uint8_t green() const ;
  uint8_t blue()  const ;


  // todo: implement methods an operators
};


std::string as_string(RgbColor);  // for println()

#endif

