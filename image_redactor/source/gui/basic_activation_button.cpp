#include "../../include/gui/button.hpp"

#include "../../../GL/include/events/mouse.hpp"

namespace GL
{

BasicActivationButton::BasicActivationButton(const Dot2d &pos, const Vector2d &size,
                                             std::shared_ptr<const Texture> &default_texture,
                                             std::shared_ptr<const Texture> &hovered_texture,
                                             std::shared_ptr<const Texture> &pressed_texture): ActivationButton(pos, size)
                                                                                             , default_texture_(default_texture)
                                                                                             , hovered_texture_(hovered_texture)
                                                                                             , pressed_texture_(pressed_texture)  {}

bool BasicActivationButton::is_hovered(BaseWindow &base_window)
{
    Vector2d mouse_pos = Mouse::get_position(base_window) - pos_;
    return ((0 <= mouse_pos.x()) && (mouse_pos.x() <= size_.x())) &&
           ((0 <= mouse_pos.y()) && (mouse_pos.y() <= size_.y()));
}


void BasicActivationButton::draw(BaseWindow &base_window)
{
    Sprite sprite;
    std::shared_ptr<const Texture> texture = nullptr;

    if(is_active_) texture = pressed_texture_;
    else
    {
        switch(state_)
        {
            case State::DEFAULT:
            {
                texture = default_texture_;
                break;
            }
            case State::HOVERED:
            case State::PRESSED:
            {
                texture = hovered_texture_;
                break;
            }
        }
    }

    sprite.set_texture(*texture.get());
    sprite.set_position(pos_);
    // sprite.set_size(size_); // TODO

    base_window.draw_sprite(sprite);
}

}; // namespace GL