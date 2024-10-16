#include "../../include/graphics/render.hpp"

namespace GL
{

Texture::Texture(const std::string &filename)
{
    sf::Texture::loadFromFile(filename);
}


bool Texture::create(const Vector2d &size)
{
    return sf::Texture::create(size.x(), size.y());
}

bool Texture::load_from_file(const std::string &filename)
{
    return sf::Texture::loadFromFile(filename);
}

}; // namespace GL