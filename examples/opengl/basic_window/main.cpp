#include "opengl_window.hpp"
#include "events.hpp"
#include "glad/glad.h"
#include <iostream>

int main()
{
    jade::window_settings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "Simple OpenGL Window";
    jade::opengl_window window = jade::opengl_window(settings);

    // Subscribe to some events
    window.on([](jade::event::window_resize_event event){
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    });
    window.on([](jade::event::key_pressed_event event) {
        std::cout << "Key pressed..." << event.key << std::endl;
    });

    // Load glad functions so we can use opengl
    glfwMakeContextCurrent(window.handle());
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!status)
    {
        std::cout << "Failed to initialise GLAD!" << std::endl;
    }
    glClearColor(191.0/255.0, 247.0/255.0, 178.0/255.0, 0.0);

    while(!window.should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        window.update();
    }
    return 0;
}
