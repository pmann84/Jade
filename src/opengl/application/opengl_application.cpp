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
    m_window->on([this](event::window_resize_event event){
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::key_pressed_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::window_close_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::text_input_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::mouse_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::scroll_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
    m_window->on([this](event::cursor_position_changed_event event) {
        for (const auto& layer : m_layer_stack) {
            layer->on(event);
        }
    });
}

float jade::opengl_application::get_time()
{
    return static_cast<float>(glfwGetTime());
}

void jade::opengl_application::poll_events()
{
    glfwPollEvents();
}
