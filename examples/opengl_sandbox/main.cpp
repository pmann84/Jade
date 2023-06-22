#include <iostream>
#include <Window.hpp>

int main()
{
    gfxlib::WindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "OpenGL Sandbox";
    const gfxlib::Window window = gfxlib::Window(settings);
    std::cout << "Hello, OpenGL Sandbox!" << std::endl;
    while(!window.shouldClose())
    {
        window.onUpdate();
    }
    return 0;
}