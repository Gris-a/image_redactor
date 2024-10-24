#include <chrono>
#include <thread>

#include "GL/GL.hpp"
#include "image_redactor/config.hpp"

int main()
{
    GL::BaseWindow window(WINDOW_SIZE);

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