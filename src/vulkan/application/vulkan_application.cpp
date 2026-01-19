#include "vulkan_application.hpp"

jade::vulkan_application::vulkan_application(application_settings settings)
            : application(std::move(settings)) {
    glfwMakeContextCurrent(m_window->handle());

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

float jade::vulkan_application::get_time()
{
    return static_cast<float>(glfwGetTime());
}

void jade::vulkan_application::poll_events()
{
    glfwPollEvents();
}
