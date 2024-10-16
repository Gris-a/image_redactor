#include "../../include/gui/button.hpp"

namespace GL
{

HoldButton::HoldButton(const Dot2d &pos, const Vector2d &size): Button(pos, size) {}


void HoldButton::on_press()
{
    for(auto &action: press_actions_) (*action)();
    time_ = std::chrono::system_clock::now();
}

void HoldButton::on_hold()
{
    static const double PPS = 10; // presses per second

    auto now = std::chrono::system_clock::now();
    if(static_cast<std::chrono::duration<double>>(now - time_).count() < 1 / PPS) return;

    for(auto &action: press_actions_) (*action)();
    time_ = now;
}

}; // namespace GL