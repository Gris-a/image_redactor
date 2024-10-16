#include "../../include/graphics/window.hpp"

namespace GL
{

WindowManager::WindowManager(const Dot2d pos, const Vector2d &size): Window(pos, size) {}


void WindowManager::add_window(std::unique_ptr<Window> &&window)
{
    windows_.push_back(std::move(window));
}


void WindowManager::handle_event(const Event &event, BaseWindow &base_window, const Vector2d &base)
{
    Vector2d base_offset = base + pos_;
    for(std::unique_ptr<Window> &window: windows_)
    {
        window->handle_event(event, base_window, base_offset);
    }
}


void WindowManager::draw(BaseWindow &base_window, const Vector2d &base)
{
    Vector2d base_offset = base + pos_;
    for(std::unique_ptr<Window> &window: windows_)
    {
        window->draw(base_window, base_offset);
    }
}

}; // namespace GL