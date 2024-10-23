#include "../../include/graphics/render.hpp"

namespace GL
{

bool Font::load_from_file(const std::string& filename)
{
    return sf::Font::loadFromFile(filename);
}


void Text::set_font(const Font &font)
{
    sf::Text::setFont(font);
}

void Text::set_style(uint32_t style)
{
    sf::Text::setStyle(style);
}

void Text::set_character_size(unsigned size)
{
    sf::Text::setCharacterSize(size);
}

void Text::set_string(const std::string& string)
{
    sf::Text::setString(string);
}

void Text::set_fill_color(const Color &color)
{
    sf::Text::setFillColor(sf::Color(uint32_t(color)));
}

void Text::set_outline_color(const Color &color)
{
    sf::Text::setOutlineColor(sf::Color(uint32_t(color)));
}

void Text::set_outline_thickness(double thickness)
{
    sf::Text::setOutlineThickness(thickness);
}


void Text::set_position(const Vector2d &pos)
{
    sf::Text::setPosition(pos.x(), pos.y());
}

void Text::set_rotation(double angle)
{
    sf::Text::setRotation(angle);
}

void Text::set_scale(const Vector2d &scale)
{
    sf::Text::setScale(sf::Vector2f(scale.x(), scale.y()));
}

}; // namespace GL