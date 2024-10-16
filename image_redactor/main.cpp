#include "../GL/GL.hpp"
#include "render_window.hpp"

const GL::Vector2d WINDOW_SIZE(1920,1080);

int main()
{
    GL::BaseWindow window(WINDOW_SIZE);

    std::unique_ptr<GL::Window> w = std::make_unique<RenderWindow>(GL::Dot2d(0, 0), WINDOW_SIZE);
    window.add_window(std::move(w));

    while(window.is_open())
    {
        window.handle_events();

        window.clear();
        window.draw();
        window.display();
    }
}