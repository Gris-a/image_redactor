#include "../../include/graphics/window.hpp"

namespace GL
{

WindowManager::WindowManager(const Dot2d pos, const Vector2d &size): Window(pos, size) {}


void WindowManager::add_window(std::unique_ptr<Window> &&window)
{
    windows_.push_back(std::move(window));
}


void WindowManager::update_self(const Event &event, BaseWindow &base_window) {}

void WindowManager::update(const Event &event, BaseWindow &base_window)
{
    if(!is_active_) return;

    update_self(event, base_window);
    for(std::unique_ptr<Window> &window: windows_)
    {
        if(window->is_active()) window->update(event, base_window);
    }
}


void WindowManager::draw_self(BaseWindow &base_window) {}

void WindowManager::draw(BaseWindow &base_window)
{
    if(!is_active_) return;

    draw_self(base_window);
    for(std::unique_ptr<Window> &window: windows_)
    {
        if(window->is_active()) window->draw(base_window);
    }
}

}; // namespace GL