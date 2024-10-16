#include "../../include/events/keyboard.hpp"

namespace GL
{

bool Keyboard::is_key_pressed(Key key)
{
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

}; // namespace GL