#pragma once

#include <algorithm>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

namespace GL
{

class Color
{
public:
    static const unsigned COLOR_MAX = 255;

private:
    unsigned red_ = 0, green_ = 0, blue_ = 0, alpha_ = COLOR_MAX;

public:
    Color() = default;
    Color(unsigned red, unsigned green, unsigned blue, unsigned alpha);

    unsigned red()   const;
    unsigned green() const;
    unsigned blue()  const;
    unsigned alpha() const;

    void set_red(unsigned red);
    void set_green(unsigned green);
    void set_blue(unsigned blue);
    void set_alpha(unsigned alpha);


    Color &operator +=(const Color &diff);

    Color &operator *=(double scale);

    friend Color operator +(const Color &color1, const Color &color2);

    friend Color operator *(const Color &color, double scale);
    friend Color operator *(double scale, const Color &color);
};

}; // namespace GL