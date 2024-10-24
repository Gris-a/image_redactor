#include "../../include/gui/button.hpp"


HoldButton::HoldButton(const GL::Dot2d &pos, const GL::Vector2d &size): Button(pos, size) {}


void HoldButton::on_hold()
{
    static const double PPS = 10; // presses per second

    auto now = std::chrono::system_clock::now();
    if(static_cast<std::chrono::duration<double>>(now - time_).count() < 1 / PPS) return;

    for(auto &action: hold_actions_) (*action)();
    time_ = now;
}