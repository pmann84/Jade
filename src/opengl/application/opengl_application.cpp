#include "opengl_application.hpp"

#include <glad/glad.h>
#include <iostream>

jade::opengl_application::opengl_application(application_settings settings)
            : application(std::move(settings)) {
    glfwMakeContextCurrent(m_window->handle());
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!status)
    {
        std::cout << "Failed to initialise GLAD!" << std::endl;
    }
}

float jade::opengl_application::get_time()
{
    return static_cast<float>(glfwGetTime());
}

void jade::opengl_application::poll_events()
{
    glfwPollEvents();
}
