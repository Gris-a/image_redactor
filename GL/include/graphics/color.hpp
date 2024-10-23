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
    struct Components
    {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
    };
    union
    {
        Components components_;
        uint32_t color_;
    };

public:
    Color();
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    Color(const Color &color);
    Color(uint32_t color);

    Color &operator =(const Color &other);

    uint8_t red()   const;
    uint8_t green() const;
    uint8_t blue()  const;
    uint8_t alpha() const;

    void set_red(uint8_t red);
    void set_green(uint8_t green);
    void set_blue(uint8_t blue);
    void set_alpha(uint8_t alpha);

    operator uint32_t() const;

    Color &operator +=(const Color &diff);

    Color &operator *=(double scale);

    friend Color operator +(const Color &color1, const Color &color2);

    friend Color operator *(const Color &color, double scale);
    friend Color operator *(double scale, const Color &color);
};

}; // namespace GL