#include "../../include/events/event.hpp"

namespace GL
{

Event::EventType Event::type() const
{
    return type_;
}

Event::KeyEvent Event::key()                  const {return sf::Event::key;}
Event::MouseMoveEvent Event::mouse_move()     const {return sf::Event::mouseMove;}
Event::MouseButtonEvent Event::mouse_button() const {return sf::Event::mouseButton;}

}; // namespace GL