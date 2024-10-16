#include "../../include/graphics/window.hpp"

#include "../../include/events/mouse.hpp"

namespace GL
{

Window::Window(const Dot2d pos, const Vector2d &size): pos_(pos), size_(size) {}


Vector2d Window::pos()  const
{
    return pos_;
}

Vector2d Window::size() const
{
    return size_;
}

bool Window::is_hovered(BaseWindow &base_window, const Vector2d &base)
{
    Vector2d mouse_pos = Mouse::get_position(base_window) - base - pos_;
    return ((0 <= mouse_pos.x()) && (mouse_pos.x() <= size_.x())) &&
           ((0 <= mouse_pos.y()) && (mouse_pos.y() <= size_.y()));
}

}; // namespace GL