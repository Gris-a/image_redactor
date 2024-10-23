#pragma once

#include <vector>
#include <memory>

#include "../../../GL/GL.hpp"

namespace GL
{
class Layer // TODO union with render texture somehow(to re-draw only active layer)
{
    friend class CanvasWindow;
    friend class Canvas;

private:
    Vector2d size_;
    std::vector<Color> pixels_;

public:
    Layer(Vector2d size);

    Color get_pixel(Vector2d pos) const;
    void set_pixel(Vector2d pos, Color pixel);
};

class Canvas
{
    friend class CanvasWindow;

private:
    size_t active_layer_;

    std::unique_ptr<Layer> preview_layer_;
    std::vector<std::unique_ptr<Layer>> layers_;

public:
    Canvas(Vector2d size);

    std::unique_ptr<Layer> &get_layer(size_t index);
    const std::unique_ptr<Layer> &get_layer(size_t index) const;

    std::unique_ptr<Layer> &get_preview_layer();
    const std::unique_ptr<Layer> &get_preview_layer() const;

    std::unique_ptr<Layer> &get_active_layer();
    const std::unique_ptr<Layer> &get_active_layer() const;

    void set_active_layer(size_t index);
    void clear_preview_layer();

    void remove_layer(size_t index);
    void insert_empty_layer(size_t index);
};

}; // namespace GL