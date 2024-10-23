#include "../../include/canvas/canvas_window.hpp"

namespace GL
{

CanvasWindow::CanvasWindow(const Dot2d pos, const Vector2d &size): Window(pos, size), canvas_(size)
{
    texture_.create(size);
}

void CanvasWindow::draw(BaseWindow &base_window)
{
    Sprite sprite;
    sprite.set_position(pos_);

    texture_.update(canvas_.preview_layer_->pixels_.data()); // TODO draw_layer func
    sprite.set_texture(texture_);
    base_window.draw_sprite(sprite);

    for(auto &layer: canvas_.layers_)
    {
        texture_.update(layer->pixels_.data());
        sprite.set_texture(texture_);
        base_window.draw_sprite(sprite);
    }
}

void CanvasWindow::update(const Event &event, BaseWindow &base_window) {} // TODO

}; // namespace GL