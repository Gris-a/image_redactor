#pragma once

#include <memory>
#include <chrono>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#include "../graphics/render.hpp"
#include "../graphics/vector.hpp"
#include "../graphics/window.hpp"

namespace GL
{

class Event;

class Action
{
public:
    virtual ~Action() {};
    virtual void operator()() = 0;
};

class Button: public Window
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

    virtual void draw(BaseWindow &base_window) = 0;
    virtual void update(const Event &event, BaseWindow &base_window) override;

    virtual bool is_hovered(BaseWindow &base_window) = 0;

    void add_action(std::vector<std::unique_ptr<Action>> &actions, std::unique_ptr<Action> &&action);

public:
    Button(const Dot2d &pos, const Vector2d &size);
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
    HoldButton(const Dot2d &pos, const Vector2d &size);
};


class ActivationButton: public Button
{
protected:
    bool is_active_ = false;

    virtual void on_release() override;

public:
    ActivationButton(const Dot2d &pos, const Vector2d &size);

    bool is_active() const;
};


class BasicHoldButton: public HoldButton
{
protected:
    std::shared_ptr<const Texture> default_texture_;
    std::shared_ptr<const Texture> hovered_texture_;
    std::shared_ptr<const Texture> pressed_texture_;

    virtual void draw(BaseWindow &base_window) override;
    virtual bool is_hovered(BaseWindow &base_window) override;

public:
    BasicHoldButton(const Dot2d &pos, const Vector2d &size,
                    std::shared_ptr<const Texture> &default_texture, std::shared_ptr<const Texture> &hovered_texture, std::shared_ptr<const Texture> &pressed_texture);
};


class BasicActivationButton: public ActivationButton
{
protected:
    std::shared_ptr<const Texture> default_texture_;
    std::shared_ptr<const Texture> hovered_texture_;
    std::shared_ptr<const Texture> pressed_texture_;

    virtual void draw(BaseWindow &base_window) override;
    virtual bool is_hovered(BaseWindow &base_window) override;

public:
    BasicActivationButton(const Dot2d &pos, const Vector2d &size,
                          std::shared_ptr<const Texture> &default_texture, std::shared_ptr<const Texture> &hovered_texture, std::shared_ptr<const Texture> &pressed_texture);
};

}; // namespace GL