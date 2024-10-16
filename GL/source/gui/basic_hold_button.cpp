#include "../../include/gui/button.hpp"

#include "../../include/events/mouse.hpp"

namespace GL
{

BasicHoldButton::BasicHoldButton(const Dot2d &pos, const Vector2d &size,
                                 const Texture *default_texture, const Texture *hovered_texture, const Texture *pressed_texture): HoldButton(pos, size)
                                                                                                                                , default_texture_(default_texture)
                                                                                                                                , hovered_texture_(hovered_texture)
                                                                                                                                , pressed_texture_(pressed_texture) {}

bool BasicHoldButton::is_hovered(BaseWindow &base_window, const Vector2d &base)
{
    Vector2d mouse_pos = Mouse::get_position(base_window) - base - pos_;
    return ((0 <= mouse_pos.x()) && (mouse_pos.x() <= size_.x())) &&
           ((0 <= mouse_pos.y()) && (mouse_pos.y() <= size_.y()));
}


void BasicHoldButton::draw(BaseWindow &base_window, const Vector2d &base)
{
    Sprite sprite;
    const Texture *texture = nullptr;

    switch(state_)
    {
        case State::DEFAULT:
        {
            texture = default_texture_;
            break;
        }
        case State::HOVERED:
        {
            texture = hovered_texture_;
            break;
        }
        case State::PRESSED:
        {
            texture = pressed_texture_;
            break;
        }
    }

    sprite.set_texture(*texture);
    sprite.set_position(base + pos_);
    sprite.set_size(size_);

    base_window.draw_sprite(sprite);
}

}; // namespace GL