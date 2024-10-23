#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "color.hpp"
#include "vector.hpp"
// TODO move, rotate, scale e.t.c., remove copypaste

namespace GL
{

class Sprite;
class Text;

class Texture: protected sf::Texture
{
    friend class Sprite;

public:
    Texture() = default;
    Texture(const std::string &filename);

    bool create(const Vector2d &size);
    void update(const Color *data);

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
    void draw_text(const Text &text);
};


class Font: protected sf::Font
{
    friend class Text;

public:
    bool load_from_file(const std::string& filename);
};

class Text: protected sf::Text
{
    friend class RenderTexture;
    friend class BaseWindow;

public:
    enum Style
    {
        Regular       = 0,
        Bold          = 1 << 0,
        Italic        = 1 << 1,
        Underlined    = 1 << 2,
        StrikeThrough = 1 << 3
    };

    void set_font(const Font &font);
    void set_style(uint32_t style);

    void set_character_size(unsigned size);
    void set_string(const std::string& string);

    void set_fill_color(const Color &color);
    void set_outline_color(const Color &color);
    void set_outline_thickness(double thickness);

    void set_position(const Vector2d &pos);
    void set_rotation(double angle);

    void set_scale(const Vector2d &scale);
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

    void set_scale(const Vector2d &scale);

    void set_color(const Color &color);
    void set_alpha(const unsigned alpha);
};

}; // namespace GL