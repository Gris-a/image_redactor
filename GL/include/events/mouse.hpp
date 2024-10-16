#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../graphics/vector.hpp"

namespace GL
{

class BaseWindow;

class Mouse
{
public:
    enum class Button
    {
        LEFT,
        RIGHT,
        MIDDLE,

        XBUTTON1,
        XBUTTON2,
    };

    Mouse() = delete;

    static bool is_button_pressed(Button button);

    static Vector2d get_position();
    static Vector2d get_position(const BaseWindow &relative_to);

    static void set_position(const Vector2d &position);
    static void set_position(const Vector2d &position, const BaseWindow &relative_to);
};

}; // namespace GL