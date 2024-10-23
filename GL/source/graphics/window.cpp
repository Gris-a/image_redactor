#include "../../include/graphics/window.hpp"

#include "../../include/events/mouse.hpp"

namespace GL
{
wid_t Window::counter = 0;

Window::Window(const Dot2d pos, const Vector2d &size): id(counter++), pos_(pos), size_(size) {if(counter == 0) [[unlikely]] throw std::exception();}


Vector2d Window::pos()  const
{
    return pos_;
}

Vector2d Window::size() const
{
    return size_;
}


bool Window::is_active()
{
    return is_active_;
}

void Window::activate()
{
    is_active_ = true;
}

void Window::disactivate()
{
    is_active_ = false;
}

bool Window::is_hovered(BaseWindow &base_window)
{
    Vector2d mouse_pos = Mouse::get_position(base_window) - pos_;
    return ((0 <= mouse_pos.x()) && (mouse_pos.x() <= size_.x())) &&
           ((0 <= mouse_pos.y()) && (mouse_pos.y() <= size_.y()));
}


Dot2d Window::get_rel_coords(const Dot2d &abs_coords) const
{
    return pos_ - abs_coords;
}

Dot2d Window::get_abs_coords(const Dot2d &rel_coords) const
{
    return pos_ + rel_coords;
}


}; // namespace GL