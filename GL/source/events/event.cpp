#include "../../include/events/event.hpp"

namespace GL
{

Event::EventType Event::type() const
{
    switch(sf::Event::type)
    {
        case sf::Event::Closed:              return EventType::CLOSED;

        case sf::Event::MouseMoved:          return EventType::MOUSE_MOVED;

        case sf::Event::MouseButtonPressed:  return EventType::MB_PRESSED;
        case sf::Event::MouseButtonReleased: return EventType::MB_RELEASED;

        default:                             return EventType::NONE;
    }
};


Event::KeyEvent Event::key()                  const {return sf::Event::key;}
Event::MouseMoveEvent Event::mouse_move()     const {return sf::Event::mouseMove;}
Event::MouseButtonEvent Event::mouse_button() const {return sf::Event::mouseButton;}

}; // namespace GL