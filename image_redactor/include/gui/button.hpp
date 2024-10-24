#pragma once

#include <memory>
#include <chrono>

#include "../../../GL/include/graphics/render.hpp"
#include "../../../GL/include/graphics/vector.hpp"
#include "../../../GL/include/graphics/window.hpp"

namespace GL
{
class Event;
}; // namespace GL

class Action
{
public:
    virtual ~Action() {};
    virtual void operator()() = 0;
};

class Button: public GL::Window
{
public:
    enum class State
    {
        PRESSED,
        HOVERED,
        DEFAULT
    };

protected:
    State state_ = State::DEFAULT;

    std::vector<std::unique_ptr<Action>> default_actions_;
    std::vector<std::unique_ptr<Action>> hover_actions_;
    std::vector<std::unique_ptr<Action>> unhover_actions_;
    std::vector<std::unique_ptr<Action>> press_actions_;
    std::vector<std::unique_ptr<Action>> hold_actions_;
    std::vector<std::unique_ptr<Action>> release_actions_;

    virtual void on_default();
    virtual void on_hover();
    virtual void on_unhover();
    virtual void on_press();
    virtual void on_release();
    virtual void on_hold();

    virtual void draw(GL::BaseWindow &base_window) = 0;
    virtual void update(const GL::Event &event, GL::BaseWindow &base_window) override;

    virtual bool is_hovered(GL::BaseWindow &base_window) = 0;

    void add_action(std::vector<std::unique_ptr<Action>> &actions, std::unique_ptr<Action> &&action);

public:
    Button(const GL::Dot2d &pos, const GL::Vector2d &size);
    virtual ~Button() {}


    void add_default_action(std::unique_ptr<Action> &&action);
    void add_hover_action(std::unique_ptr<Action> &&action);
    void add_unhover_action(std::unique_ptr<Action> &&action);
    void add_press_action(std::unique_ptr<Action> &&action);
    void add_hold_action(std::unique_ptr<Action> &&action);
    void add_release_action(std::unique_ptr<Action> &&action);
};


class HoldButton: public Button
{
protected:
    std::chrono::time_point<std::chrono::system_clock>
    time_ = std::chrono::system_clock::now();

    virtual void on_hold() override;

public:
    HoldButton(const GL::Dot2d &pos, const GL::Vector2d &size);
};


class ActivationButton: public Button
{
protected:
    bool is_active_ = false;

    virtual void on_release() override;

public:
    ActivationButton(const GL::Dot2d &pos, const GL::Vector2d &size);

    bool is_active() const;
};


class BasicHoldButton: public HoldButton
{
protected:
    std::shared_ptr<const GL::Texture> default_texture_;
    std::shared_ptr<const GL::Texture> hovered_texture_;
    std::shared_ptr<const GL::Texture> pressed_texture_;

    virtual void draw(GL::BaseWindow &base_window) override;
    virtual bool is_hovered(GL::BaseWindow &base_window) override;

public:
    BasicHoldButton(const GL::Dot2d &pos, const GL::Vector2d &size,
                    std::shared_ptr<const GL::Texture> &default_texture, std::shared_ptr<const GL::Texture> &hovered_texture, std::shared_ptr<const GL::Texture> &pressed_texture);
};


class BasicActivationButton: public ActivationButton
{
protected:
    std::shared_ptr<const GL::Texture> default_texture_;
    std::shared_ptr<const GL::Texture> hovered_texture_;
    std::shared_ptr<const GL::Texture> pressed_texture_;

    virtual void draw(GL::BaseWindow &base_window) override;
    virtual bool is_hovered(GL::BaseWindow &base_window) override;

public:
    BasicActivationButton(const GL::Dot2d &pos, const GL::Vector2d &size,
                          std::shared_ptr<const GL::Texture> &default_texture, std::shared_ptr<const GL::Texture> &hovered_texture, std::shared_ptr<const GL::Texture> &pressed_texture);
};