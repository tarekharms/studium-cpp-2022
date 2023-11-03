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

    s+=std::to_string(c.m_red);
    s+=std::string(", ");
    s+=std::to_string(c.m_green);
    s+=std::string(", ");
    s+=std::to_string(c.m_blue);

    s+=std::string(")");
    return s;
}

RgbColor addRgbColors(RgbColor left, RgbColor right)
{
    RgbColor result;
    uint16_t red = addColors(left.m_red, right.m_red);
    uint16_t green = addColors(left.m_green, right.m_green);
    uint16_t blue = addColors(left.m_blue, right.m_blue);
    return RgbColor(red, green, blue);
}

uint8_t addColors(uint8_t left, uint8_t right)
{
    uint16_t result = left + right;

    if(result > 255)
    {
        return 255;
    }
    else
    {
        return result;
    }
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

RgbColor& RgbColor::operator+=(const RgbColor& color)
{
   m_red = addColors(m_red, color.m_red);
   m_green = addColors(m_green, color.m_green);
   m_blue = addColors(m_blue, color.m_blue);
   return *this;
} 

int RgbColor::luminosity()
{
   return (int)(0.21 * m_red + 0.72 * m_green + 0.07 * m_blue);
} 
