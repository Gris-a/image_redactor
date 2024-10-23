#include "../../include/graphics/color.hpp"

namespace GL
{

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha): components_{red, green, blue, alpha} {}
Color::Color(const Color &color): color_(color.color_) {}
Color::Color(uint32_t color): color_(color) {}


uint8_t Color::red()   const {return components_.red;}
uint8_t Color::green() const {return components_.green;}
uint8_t Color::blue()  const {return components_.blue;}
uint8_t Color::alpha() const {return components_.alpha;}


void Color::set_red(uint8_t red)     {components_.red   = red;}
void Color::set_green(uint8_t green) {components_.green = green;}
void Color::set_blue(uint8_t blue)   {components_.blue  = blue;}
void Color::set_alpha(uint8_t alpha) {components_.alpha = alpha;}


Color::operator uint32_t() const
{
    return color_;
}


Color &Color::operator +=(const Color &diff)
{
    components_.red   = std::min(COLOR_MAX, static_cast<unsigned>(components_.red   + diff.components_.red));
    components_.green = std::min(COLOR_MAX, static_cast<unsigned>(components_.green + diff.components_.green));
    components_.blue  = std::min(COLOR_MAX, static_cast<unsigned>(components_.blue  + diff.components_.blue));
    components_.alpha = std::max(components_.alpha, diff.components_.alpha);

    return *this;
}


Color &Color::operator *=(double scale)
{
    components_.red   = std::min(COLOR_MAX, static_cast<unsigned>(components_.red   * scale));
    components_.green = std::min(COLOR_MAX, static_cast<unsigned>(components_.green * scale));
    components_.blue  = std::min(COLOR_MAX, static_cast<unsigned>(components_.blue  * scale));

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