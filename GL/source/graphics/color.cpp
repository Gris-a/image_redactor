#include "../../include/graphics/color.hpp"

namespace GL
{

Color::Color(unsigned red, unsigned green, unsigned blue, unsigned alpha): red_(red), green_(green), blue_(blue), alpha_(alpha) {}

unsigned Color::red()   const {return red_;}
unsigned Color::green() const {return green_;}
unsigned Color::blue()  const {return blue_;}
unsigned Color::alpha() const {return alpha_;}


void Color::set_red(unsigned red)     {red_   = red;}
void Color::set_green(unsigned green) {green_ = green;}
void Color::set_blue(unsigned blue)   {blue_  = blue;}
void Color::set_alpha(unsigned alpha) {alpha_ = alpha;}


Color &Color::operator +=(const Color &diff)
{
    red_   = std::min(COLOR_MAX, red_   + diff.red_);
    green_ = std::min(COLOR_MAX, green_ + diff.green_);
    blue_  = std::min(COLOR_MAX, blue_  + diff.blue_);
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