#include "../../include/events/mouse.hpp"

#include "../../include/graphics/vector.hpp"
#include "../../include/graphics/window.hpp"

namespace GL
{

bool Mouse::is_button_pressed(Button button)
{
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}


Vector2d Mouse::get_position()
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition();
    return Vector2d(mouse_pos.x, mouse_pos.y);
}

Vector2d Mouse::get_position(const BaseWindow &relative_to)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(relative_to);
    return Vector2d(mouse_pos.x, mouse_pos.y);
}


void Mouse::set_position(const Vector2d &position)
{
    sf::Mouse::setPosition(sf::Vector2i(position.x(), position.y()));
}

void Mouse::set_position(const Vector2d &position, const BaseWindow &relative_to)
{
    sf::Mouse::setPosition(sf::Vector2i(position.x(), position.y()), relative_to);
}

}; // namespace GL