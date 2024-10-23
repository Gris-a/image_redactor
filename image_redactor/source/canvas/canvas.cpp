#include "../../include/canvas/canvas.hpp"

namespace GL
{

Layer::Layer(Vector2d size): size_(size), pixels_(size.x() * size.y()) {}


Color Layer::get_pixel(Vector2d pos) const
{
    return pixels_[pos.y() * size_.x() + pos.x()];
}

void Layer::set_pixel(Vector2d pos, Color pixel)
{
    pixels_[pos.y() * size_.x() + pos.x()] = pixel;
}


Canvas::Canvas(Vector2d size): active_layer_(0), preview_layer_(std::make_unique<Layer>(size))
{
    layers_.push_back(std::make_unique<Layer>(size));
}


std::unique_ptr<Layer> &Canvas::get_layer(size_t index)
{
    return layers_[index];
}

const std::unique_ptr<Layer> &Canvas::get_layer(size_t index) const
{
    return layers_[index];
}


std::unique_ptr<Layer> &Canvas::get_preview_layer()
{
    return preview_layer_;
}

const std::unique_ptr<Layer> &Canvas::get_preview_layer() const
{
    return preview_layer_;
}


std::unique_ptr<Layer> &Canvas::get_active_layer()
{
    return layers_[active_layer_];
}

const std::unique_ptr<Layer> &Canvas::get_active_layer() const
{
    return layers_[active_layer_];
}


void Canvas::set_active_layer(size_t index)
{
    active_layer_ = index;
}

void Canvas::clear_preview_layer()
{
    Layer temp = Layer(preview_layer_->size_);
    swap(temp.pixels_, preview_layer_->pixels_);
}


void Canvas::remove_layer(size_t index)
{
    layers_.erase(layers_.begin() + index);
}

void Canvas::insert_empty_layer(size_t index)
{
    layers_.insert(layers_.begin() + index, std::make_unique<Layer>(preview_layer_->size_));
}

}; // namespace GL