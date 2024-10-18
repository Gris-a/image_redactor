#include <chrono>
#include <thread>

#include "GL/GL.hpp"

void load_pluggins(GL::BaseWindow &window);
void main_loop(GL::BaseWindow &window);

const GL::Vector2d WINDOW_SIZE(1920,1080);
const double FPS = 60;


int main()
{
    GL::BaseWindow window(WINDOW_SIZE);
    load_pluggins(window);

    main_loop(window);
}


void main_loop(GL::BaseWindow &window)
{
    while(window.is_open())
    {
        auto time = std::chrono::system_clock::now();

        window.update();
        window.clear();
        window.draw();
        window.display();

        std::this_thread::sleep_until(time + std::chrono::milliseconds(static_cast<int64_t>(1 / FPS * 1000)));
    }
}

void load_pluggins(GL::BaseWindow &window) {}