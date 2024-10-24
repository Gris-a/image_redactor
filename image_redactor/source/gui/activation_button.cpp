#include "../../include/gui/button.hpp"


ActivationButton::ActivationButton(const GL::Dot2d &pos, const GL::Vector2d &size): Button(pos, size) {}


bool ActivationButton::is_active() const
{
    return is_active_;
}


void ActivationButton::on_release()
{
    is_active_ = !is_active_;
    for(auto &action: release_actions_) (*action)();
}