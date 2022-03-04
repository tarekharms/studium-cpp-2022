#include "rgbColor.hpp"

RgbColor::RgbColor()
: m_red(0), m_green(0), m_blue(0)
{
}

RgbColor::RgbColor(uint32_t rgbVal){
  m_red   = (rgbVal & 0xff0000) >> 16;
  m_green = (rgbVal & 0xff00) >> 8;
  m_blue  = (rgbVal & 0xff);
}



uint8_t RgbColor::red() const {
	return m_red; //FIXME: return >255 correctly
}

uint8_t RgbColor::green() const {
	return m_green; //FIXME: return >255 correctly
}

uint8_t RgbColor::blue() const {
	return m_blue; //FIXME: return >255 correctly
}


std::string as_string(RgbColor c){  // for println()
  std::string s("col(");

  s+=std::string(")");
  return s;
}

