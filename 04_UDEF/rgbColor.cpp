#include "rgbColor.hpp"

RgbColor::RgbColor()
: m_red(0), m_green(0), m_blue(0)
{
}

RgbColor::RgbColor(uint32_t red, uint32_t green, uint32_t blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
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

    // s+=std::string(c.m_red);

    s+=std::string(")");
    return s;
}

RgbColor addRgbColors(RgbColor left, RgbColor right)
{
    RgbColor result;
    uint8_t red = left.m_red + right.m_red;
    uint8_t green = left.m_green + right.m_green;
    uint8_t blue = left.m_blue + right.m_blue;
    return RgbColor(red, green, blue);
}

RgbColor operator+ (RgbColor left, RgbColor right)
{
    return addRgbColors(left, right);
}

RgbColor& RgbColor::operator++() {
    this->m_red = (this->m_red << 1 ) | 0x01;
    this->m_green = (this->m_green << 1) | 0x01;
    this->m_blue = (this->m_blue << 1) | 0x01;
    return *this;
}

RgbColor::operator unsigned int() {
    return (this->m_red * 65536 + this->m_green * 256 + this->m_blue);
}

int RgbColor::luminosity()
{
   return 0;
} 
