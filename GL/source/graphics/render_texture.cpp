#include "../../include/graphics/render.hpp"

namespace GL
{

bool RenderTexture::create(const Vector2d &size)
{
    return sf::RenderTexture::create(size.x(), size.y());
}

const sf::Texture &RenderTexture::get_texture() const
{
    return sf::RenderTexture::getTexture();
}


void RenderTexture::clear()
{
    sf::RenderTexture::clear();
}

void RenderTexture::update()
{
    sf::RenderTexture::display();
}


void RenderTexture::draw_sprite(const Sprite &sprite)
{
    sf::RenderTexture::draw(sprite);
}

void RenderTexture::draw_text(const Text &text)
{
    sf::RenderTexture::draw(text);
}

}; // namespace GL