#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "color.hpp"
#include "vector.hpp"

namespace GL
{

class Sprite;

class Texture: protected sf::Texture
{
    friend class Sprite;

public:
    Texture(const std::string &filename);

    bool create(const Vector2d &size);
    bool load_from_file(const std::string &filename);
};


class RenderTexture: protected sf::RenderTexture
{
    friend class Sprite;

private:
    const sf::Texture &get_texture() const;

public:
    bool create(const Vector2d &size);

    void clear();
    void update();

    void draw_sprite(const Sprite &sprite); // TODO draw primitives
};


class Sprite: protected sf::Sprite
{
    friend class RenderTexture;
    friend class BaseWindow;

public:
    void set_texture(const Texture &texture);
    void set_texture(const RenderTexture &texture);

    void set_position(const Vector2d &pos);
    void set_rotation(double angle);

    void set_size(const Vector2d &size);
    void set_scale(const Vector2d &scale);

    void set_color(const Color &color);
    void set_alpha(const unsigned alpha);
};

}; // namespace GL