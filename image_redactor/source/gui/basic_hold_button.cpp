#include "../../include/gui/button.hpp"

#include "../../../GL/include/events/mouse.hpp"


BasicHoldButton::BasicHoldButton(const GL::Dot2d &pos, const GL::Vector2d &size,
                                 std::shared_ptr<const GL::Texture> &default_texture,
                                 std::shared_ptr<const GL::Texture> &hovered_texture,
                                 std::shared_ptr<const GL::Texture> &pressed_texture): HoldButton(pos, size)
                                                                                     , default_texture_(default_texture)
                                                                                     , hovered_texture_(hovered_texture)
                                                                                     , pressed_texture_(pressed_texture) {}

bool BasicHoldButton::is_hovered(GL::BaseWindow &base_window)
{
    GL::Vector2d mouse_pos = GL::Mouse::get_position(base_window) - pos_;
    return ((0 <= mouse_pos.x()) && (mouse_pos.x() <= size_.x())) &&
           ((0 <= mouse_pos.y()) && (mouse_pos.y() <= size_.y()));
}


void BasicHoldButton::draw(GL::BaseWindow &base_window)
{
    GL::Sprite sprite;
    std::shared_ptr<const GL::Texture> texture = nullptr;

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

    sprite.set_texture(*texture.get());
    sprite.set_position(pos_);
    // sprite.set_size(size_); // TODO

    base_window.draw_sprite(sprite);
}