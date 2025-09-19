#include "opengl_application.hpp"

float jade::opengl_application::get_time()
{
    return static_cast<float>(glfwGetTime());
}

void jade::opengl_application::poll_events()
{
    glfwPollEvents();
}
