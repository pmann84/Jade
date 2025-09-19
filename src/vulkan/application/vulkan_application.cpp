#include "vulkan_application.hpp"

jade::vulkan_application::vulkan_application(application_settings settings)
            : application(std::move(settings)) {
    glfwMakeContextCurrent(m_window->handle());

}

float jade::vulkan_application::get_time()
{
    return static_cast<float>(glfwGetTime());
}

void jade::vulkan_application::poll_events()
{
    glfwPollEvents();
}
