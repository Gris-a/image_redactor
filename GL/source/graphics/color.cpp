#include "../../include/graphics/color.hpp"

namespace GL
{

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha): red_(red), green_(green), blue_(blue), alpha_(alpha) {}

uint8_t Color::red()   const {return red_;}
uint8_t Color::green() const {return green_;}
uint8_t Color::blue()  const {return blue_;}
uint8_t Color::alpha() const {return alpha_;}


void Color::set_red(uint8_t red)     {red_   = red;}
void Color::set_green(uint8_t green) {green_ = green;}
void Color::set_blue(uint8_t blue)   {blue_  = blue;}
void Color::set_alpha(uint8_t alpha) {alpha_ = alpha;}


Color &Color::operator +=(const Color &diff)
{
    red_   = std::min(COLOR_MAX, static_cast<unsigned>(red_   + diff.red_));
    green_ = std::min(COLOR_MAX, static_cast<unsigned>(green_ + diff.green_));
    blue_  = std::min(COLOR_MAX, static_cast<unsigned>(blue_  + diff.blue_));
    alpha_ = std::max(alpha_, diff.alpha_);

    return *this;
}


Color &Color::operator *=(double scale)
{
    red_   = std::min(COLOR_MAX, static_cast<unsigned>(red_   * scale));
    green_ = std::min(COLOR_MAX, static_cast<unsigned>(green_ * scale));
    blue_  = std::min(COLOR_MAX, static_cast<unsigned>(blue_  * scale));

    return *this;
}


Color operator +(const Color &color1, const Color &color2)
{
    Color res = color1;
    res += color2;

    return res;
}


Color operator *(const Color &color, double scale)
{
    Color res = color;
    res *= scale;

    return res;
}

Color operator *(double scale, const Color &color)
{
    Color res = color;
    res *= scale;

    return res;
}

}; // namespace GL