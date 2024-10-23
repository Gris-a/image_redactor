#pragma once

#include "canvas.hpp"

namespace GL
{

class CanvasWindow: public Window
{
private:
    Canvas canvas_;
    Texture texture_;

public:
    CanvasWindow(const Dot2d pos, const Vector2d &size);

    virtual void draw(BaseWindow &base_window) override;
    virtual void update(const Event &event, BaseWindow &base_window) override;
};

}; // namespace GL