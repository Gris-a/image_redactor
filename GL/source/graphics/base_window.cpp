#include "../../include/graphics/window.hpp"

#include "../../include/events/event.hpp"
#include "../../include/graphics/render.hpp"

namespace GL
{

BaseWindow::BaseWindow(const Vector2d &size, const std::string &title): sf::RenderWindow(sf::VideoMode(size.x(), size.y()), title, sf::Style::Default)
                                                                      , WindowManager(Vector2d(0, 0), size)
{
    sf::RenderWindow::setPosition(sf::Vector2i(0, 0));
}

BaseWindow::BaseWindow(const Vector2d &size, const Vector2d &render_pos, const Vector2d &render_size, const std::string &title): sf::RenderWindow(sf::VideoMode(size.x(), size.y()), title, sf::Style::Titlebar | sf::Style::Close)
                                                                                                                               , WindowManager(render_pos, render_size)
{
    sf::RenderWindow::setPosition(sf::Vector2i(0, 0));
}


bool BaseWindow::is_open() const
{
    return sf::RenderWindow::isOpen();
}


void BaseWindow::close()
{
    sf::RenderWindow::close();
}

void BaseWindow::proceed_close_event()
{
    close();
}


void BaseWindow::clear()
{
    sf::RenderWindow::clear();
}

void BaseWindow::display()
{
    sf::RenderWindow::display();
}


bool BaseWindow::poll_event(Event &event)
{
    while(sf::RenderWindow::pollEvent(event))
    {
        switch(event.sf::Event::type)
        {
            case sf::Event::Closed:
                event.type_ = Event::EventType::CLOSED;
                return true;
            case sf::Event::MouseMoved:
                event.type_ = Event::EventType::MOUSE_MOVED;
                return true;
            case sf::Event::MouseButtonPressed:
                event.type_ = Event::EventType::MB_PRESSED;
                return true;
            case sf::Event::MouseButtonReleased:
                event.type_ = Event::EventType::MB_RELEASED;
                return true;
            default:
                event.type_ = Event::EventType::NONE;
        }
    }

    return false;
}

void BaseWindow::update()
{
    Event event;
    while(poll_event(event))
    {
        if(event.type() == GL::Event::EventType::CLOSED)
        {
            proceed_close_event();
            return;
        }
        WindowManager::update(event, *this);
    }
    WindowManager::update(event, *this);
}


void BaseWindow::draw()
{
    WindowManager::draw(*this);
}

void BaseWindow::draw_sprite(const Sprite &sprite)
{
    sf::RenderWindow::draw(sprite);
}

void BaseWindow::draw_text(const Text &text)
{
    sf::RenderWindow::draw(text);
}

}; // namespace GL