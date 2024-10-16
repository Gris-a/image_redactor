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
        if(event.type() != Event::EventType::NONE)
        {
            return true;
        }
    }
    return false;
}

void BaseWindow::handle_events()
{
    Event event;
    while(poll_event(event))
    {
        if(event.type() == GL::Event::EventType::CLOSED)
        {
            close();
            return;
        }
        WindowManager::handle_event(event, *this, pos_);
    }
    WindowManager::handle_event(event, *this, pos_);
}


void BaseWindow::draw()
{
    WindowManager::draw(*this, pos_);
}

void BaseWindow::draw_sprite(const Sprite &sprite)
{
    sf::RenderWindow::draw(sprite);
}

}; // namespace GL