#include "../../include/graphics/render.hpp"

namespace GL
{

void Sprite::set_texture(const Texture &texture)
{
    sf::Sprite::setTexture(texture);
}

void Sprite::set_texture(const RenderTexture &texture)
{
    sf::Sprite::setTexture(texture.get_texture());
}


void Sprite::set_position(const Vector2d &pos)
{
    sf::Sprite::setPosition(pos.x(), pos.y());
}

void Sprite::set_rotation(double angle)
{
    sf::Sprite::setRotation(angle);
}


void Sprite::set_size(const Vector2d &size)
{
    const sf::Texture *texture = sf::Sprite::getTexture();
    sf::Vector2u texture_size = (*texture).getSize();
    set_scale(Vector2d(size.x() / texture_size.x, size.y() / texture_size.y));
}

void Sprite::set_scale(const Vector2d &scale)
{
    sf::Sprite::setScale(sf::Vector2f(scale.x(), scale.y()));
}


void Sprite::set_color(const Color &color)
{
    sf::Sprite::setColor(sf::Color(color.red(), color.green(), color.blue(), color.alpha()));
}

void Sprite::set_alpha(const unsigned alpha)
{
    sf::Color color = sf::Sprite::getColor();
    color.a = alpha;

    sf::Sprite::setColor(color);
}

}; // namespace GL