#pragma once

#include <memory>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "vector.hpp"

namespace GL
{

class Event;
class Sprite;

class BaseWindow;

class Window
{
    friend class WindowManager;

protected:
    Dot2d pos_;
    Vector2d size_;

    virtual void draw(BaseWindow &base_window, const Vector2d &base) = 0; // TODO pass drawing region
    virtual void handle_event(const Event &event, BaseWindow &base_window, const Vector2d &base) = 0;
    virtual bool is_hovered(BaseWindow &base_window, const Vector2d &base);

public:
    Window(const Dot2d pos, const Vector2d &size);
    virtual ~Window() {}

    Vector2d pos()  const;
    Vector2d size() const;
};


class WindowManager: public Window
{
    friend class BaseWindow;

protected:
    std::vector<std::unique_ptr<Window>> windows_;

    virtual void draw(BaseWindow &base_window, const Vector2d &base) override;
    virtual void handle_event(const Event &event, BaseWindow &base_window, const Vector2d &base) override;

public:
    WindowManager(const Dot2d pos, const Vector2d &size);
    void add_window(std::unique_ptr<Window> &&window);
};


class BaseWindow: protected sf::RenderWindow, public WindowManager
{
    friend class Mouse;

private:
    bool poll_event(Event &event);

protected:

public:
    BaseWindow(const Vector2d &size, const std::string &title = "");
    BaseWindow(const Vector2d &size, const Vector2d &render_pos, const Vector2d &render_size, const std::string &title = "");

    bool is_open() const;

    void close();
    void handle_events();

    void clear();
    void display();

    void draw();
    void draw_sprite(const Sprite &sprite); // TODO draw primitives
};

}; // namespace GL