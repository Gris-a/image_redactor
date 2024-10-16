#pragma once

#include "../GL/GL.hpp"

GL::Texture texture("image_redactor/assets/Jesus.png");

class RenderWindow: public GL::Window
{
private:
    const static unsigned ALPHA = 128;

    GL::RenderTexture layer1_;
    GL::RenderTexture layer2_;

    bool is_activated = false;
    GL::Dot2d mouse_press_pos;

protected:
    virtual void draw(GL::BaseWindow &base_window, const GL::Vector2d &base) override
    {
        GL::Sprite sprite1;
        sprite1.set_texture(layer1_);
        sprite1.set_position(base + pos_);
        base_window.draw_sprite(sprite1);

        GL::Sprite sprite2;
        sprite2.set_texture(layer2_);
        sprite2.set_position(base + pos_);
        sprite2.set_alpha(ALPHA);
        base_window.draw_sprite(sprite2);
    }

    virtual void handle_event(const GL::Event &event, GL::BaseWindow &base_window, const GL::Vector2d &base) override
    {
        switch(event.type())
        {
            case GL::Event::EventType::MB_PRESSED:
            {
                GL::Event::MouseButtonEvent mouse_event = event.mouse_button();
                if(is_activated || (mouse_event.button != GL::Mouse::Button::LEFT) || !is_hovered(base_window, base)) return;

                is_activated = true;
                mouse_press_pos = GL::Dot2d(mouse_event.x, mouse_event.y);

                return;
            }
            case GL::Event::EventType::MOUSE_MOVED:
            {
                if(!is_activated) return;

                layer2_.clear();

                GL::Event::MouseMoveEvent mouse_event = event.mouse_move();
                GL::Dot2d mouse_pos = GL::Dot2d(mouse_event.x, mouse_event.y);

                GL::Sprite sprite;
                sprite.set_texture(texture);
                sprite.set_position(mouse_press_pos - base - pos_);
                sprite.set_size(mouse_pos - mouse_press_pos);

                layer2_.draw_sprite(sprite);
                layer2_.update();

                return;
            }
            case GL::Event::EventType::MB_RELEASED:
            {
                GL::Event::MouseButtonEvent mouse_event = event.mouse_button();
                if(!is_activated || (mouse_event.button != GL::Mouse::Button::LEFT)) return;

                layer2_.clear();
                is_activated = false;

                if(!is_hovered(base_window, base)) return;
                GL::Dot2d mouse_pos = GL::Dot2d(mouse_event.x, mouse_event.y);

                GL::Sprite sprite;
                sprite.set_texture(texture);
                sprite.set_position(mouse_press_pos - base - pos_);
                sprite.set_size(mouse_pos - mouse_press_pos);

                layer1_.draw_sprite(sprite);
                layer1_.update();

                return;
            }
            default: return;
        }
    }

public:
    RenderWindow(const GL::Dot2d pos, const GL::Vector2d &size): GL::Window(pos, size)
    {
        layer1_.create(size);
        layer2_.create(size);
    }
};