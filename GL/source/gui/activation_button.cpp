#include "../../include/gui/button.hpp"

namespace GL
{

ActivationButton::ActivationButton(const Dot2d &pos, const Vector2d &size): Button(pos, size) {}


bool ActivationButton::is_active() const
{
    return is_active_;
}


void ActivationButton::on_release()
{
    is_active_ = !is_active_;
    for(auto &action: release_actions_) (*action)();
}

}; // namespace GL