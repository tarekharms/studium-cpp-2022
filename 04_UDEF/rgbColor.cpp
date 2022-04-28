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

RgbColor::RgbColor(uint32_t red, uint32_t green, uint32_t blue) 
{
    m_red = red;
    m_green = green;
    m_blue = blue;
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

RgbColor operator+(RgbColor left, RgbColor right)
{
    uint8_t red = addColor(left.red(), right.red());
    uint8_t green = addColor(left.green(), right.green());
    uint8_t blue = addColor(left.blue(), right.blue());

    return RgbColor(red, green, blue);
}

uint8_t addColor(uint8_t left, uint8_t right)
{
    int color = left + right;
    if(color > 255) 
    {
        return 255;
    }
    else 
    {
        return color;
    }
}

RgbColor::operator unsigned int()
{
    return (this->red() * 65536 + this->green() * 256 + this->blue());
}

RgbColor& RgbColor::operator++()
{
    return *this;
}

uint8_t RgbColor::luminosity()
{
    return 0;
}

std::string as_string(RgbColor c){  // for println()
  std::string s("col(");

  s+=std::string(")");
  return s;
}

