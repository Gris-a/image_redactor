#pragma once

#include <memory>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "vector.hpp"

namespace GL
{

using wid_t = ssize_t;

class Event;

class Sprite;
class Text;

class BaseWindow;

class Window
{
    friend class WindowManager;

private:
    static wid_t counter;
protected:
    wid_t id;

    Dot2d pos_;
    Vector2d size_;

    virtual void draw(BaseWindow &base_window)                       = 0;
    virtual void update(const Event &event, BaseWindow &base_window) = 0;

    virtual bool is_hovered(BaseWindow &base_window);

public:
    Window(const Dot2d pos, const Vector2d &size);
    virtual ~Window() {}

    Vector2d pos()  const;
    Vector2d size() const;

    Dot2d get_rel_coords(const Dot2d &abs_coords) const;
    Dot2d get_abs_coords(const Dot2d &rel_coords) const;
};


class WindowManager: public Window
{
    friend class BaseWindow;

protected:
    std::vector<std::unique_ptr<Window>> windows_;

    virtual void draw_self(BaseWindow &base_window);
    virtual void draw(BaseWindow &base_window) override;

    virtual void update_self(const Event &event, BaseWindow &base_window);
    virtual void update(const Event &event, BaseWindow &base_window) override;

public:
    WindowManager(const Dot2d pos, const Vector2d &size);
    void add_window(std::unique_ptr<Window> &&window);
};


class BaseWindow: protected sf::RenderWindow, public WindowManager
{
    friend class Mouse;

public:
    BaseWindow(const Vector2d &size, const std::string &title = "");
    BaseWindow(const Vector2d &size, const Vector2d &render_pos, const Vector2d &render_size, const std::string &title = "");

    bool is_open() const;

    void close();
    virtual void proceed_close_event();

    bool poll_event(Event &event);
    void update();

    void clear();
    void display();

    void draw();
    void draw_sprite(const Sprite &sprite);
    void draw_text(const Text &text);
};

}; // namespace GL