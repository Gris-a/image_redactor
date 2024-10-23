#include "../../include/gui/button.hpp"

#include "../../../GL/include/events/event.hpp"

namespace GL
{

Button::Button(const Dot2d &pos, const Vector2d &size): Window(pos, size) {}


void Button::on_default()
{
    for(auto &action: default_actions_) (*action)();
}

void Button::on_hover()
{
    for(auto &action: hover_actions_) (*action)();
}

void Button::on_unhover()
{
    for(auto &action: unhover_actions_) (*action)();
}

void Button::on_press()
{
    for(auto &action: press_actions_) (*action)();
}

void Button::on_hold()
{
    for(auto &action: hold_actions_) (*action)();
}

void Button::on_release()
{
    for(auto &action: release_actions_) (*action)();
}


void Button::update(const Event &event, BaseWindow &base_window)
{
    on_default();

    if(!is_hovered(base_window))
    {
        switch(state_)
        {
            case State::DEFAULT:
            {
                return;
            }
            case State::PRESSED: // fall through
            {
                on_release();
            }
            case State::HOVERED: // fall through
            {
                on_unhover();
                state_ = State::DEFAULT;
            }
            default: return;
        }
    }

    switch(event.type())
    {
        case Event::EventType::MOUSE_MOVED:
        {
            if(state_ == State::DEFAULT) on_hover();
            state_ = State::HOVERED;

            return;
        }
        case Event::EventType::MB_PRESSED:
        {
            if(event.mouse_button().button != Mouse::Button::LEFT) return;

            (state_ == State::PRESSED) ? on_hold() : on_press();
            state_ = State::PRESSED;

            return;
        }
        case Event::EventType::MB_RELEASED:
        {
            if(event.mouse_button().button != Mouse::Button::LEFT) return;

            on_release();
            state_ = State::HOVERED;

            return;
        }
        default: return;
    }
}


void Button::add_action(std::vector<std::unique_ptr<Action>> &actions, std::unique_ptr<Action> &&action)
{
    actions.push_back(std::move(action));
}

void Button::add_default_action(std::unique_ptr<Action> &&action)
{
    add_action(default_actions_, std::move(action));
}

void Button::add_hover_action(std::unique_ptr<Action> &&action)
{
    add_action(hover_actions_, std::move(action));
}

void Button::add_unhover_action(std::unique_ptr<Action> &&action)
{
    add_action(unhover_actions_, std::move(action));
}

void Button::add_press_action(std::unique_ptr<Action> &&action)
{
    add_action(press_actions_, std::move(action));
}

void Button::add_hold_action(std::unique_ptr<Action> &&action)
{
    add_action(hold_actions_, std::move(action));
}

void Button::add_release_action(std::unique_ptr<Action> &&action)
{
    add_action(release_actions_, std::move(action));
}

}; // namespace GL