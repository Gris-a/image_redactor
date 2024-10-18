#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "keyboard.hpp"
#include "mouse.hpp"

namespace GL
{

class Event: protected sf::Event
{
    friend class BaseWindow;

public:
    enum class EventType
    {
        CLOSED,

        MOUSE_MOVED,

        MB_PRESSED,
        MB_RELEASED,

        NONE
    };

    class KeyEvent
    {
        friend class Event;

    public:
        Keyboard::Key code;
        bool          alt;
        bool          control;
        bool          shift;

    private:
        KeyEvent(const sf::Event::KeyEvent &event): code(static_cast<Keyboard::Key>(event.code)), alt(event.alt), control(event.control), shift(event.shift) {}
    };

    class MouseMoveEvent
    {
        friend class Event;

    public:
        Vector2d pos;

    private:
        MouseMoveEvent(const sf::Event::MouseMoveEvent &event): pos(event.x, event.y) {}
    };

    class MouseButtonEvent
    {
        friend class Event;

    public:
        Mouse::Button button;
        Vector2d pos;

    private:
        MouseButtonEvent(const sf::Event::MouseButtonEvent &event): button(static_cast<Mouse::Button>(event.button)), pos(event.x, event.y) {}
    };

    EventType type() const;

    KeyEvent key() const;
    MouseMoveEvent mouse_move() const;
    MouseButtonEvent mouse_button() const;
};

}; // namespace GL