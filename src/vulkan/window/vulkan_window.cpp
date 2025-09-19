#include "vulkan_window.hpp"

#include <iostream>

#include "../../../vendor/glfw/include/GLFW/glfw3.h"

static void error_callback(int error, const char* description)
{
    std:: cerr << "GLFW Error (" << error << "): "<< description << std::endl;
}

namespace jade {
    vulkan_window::vulkan_window(window_settings settings) : window(std::move(settings))
    {
        if (!glfwInit())
        {
            std::cout << "Failed to initialise GLFW!" << std::endl;
            return;
        }

        glfwSetErrorCallback(error_callback);

        m_window = glfwCreateWindow(m_settings.width, m_settings.height, m_settings.title.c_str(), nullptr, nullptr);
        if (!m_window)
        {
            glfwTerminate();
            return;
        }

        glfwSetWindowUserPointer(m_window, this);

        glfwMakeContextCurrent(m_window);
    }

    vulkan_window::~vulkan_window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    bool vulkan_window::should_close() const
    {
        return glfwWindowShouldClose(m_window);
    }

    [[maybe_unused]] glm::vec2 vulkan_window::get_cursor_position()
    {
        double xPos, yPos;
        glfwGetCursorPos(m_window, &xPos, &yPos);
        return {xPos, yPos};
    }

    vulkan_window& vulkan_window::get_window(GLFWwindow* window) {
        return *static_cast<vulkan_window*>(glfwGetWindowUserPointer(window));
    }

    void vulkan_window::update() {
        glfwSwapBuffers(handle());
    }

    void vulkan_window::on(EventCallbackFnT<event::window_resize_event> callback) {
        m_window_resize_callback = callback;
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height){
            vulkan_window& win = get_window(window);
            win.m_settings.width = width;
            win.m_settings.height = height;
            event::window_resize_event event{};
            event.width = width;
            event.height = height;
            win.m_window_resize_callback(event);
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::key_pressed_event> callback) {
        m_key_pressed_callback = callback;
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            const vulkan_window& win = get_window(window);
            event::key_pressed_event event{};
            event.key = key;
            event.scancode = scancode;
            event.action = action;
            event.mods = mods;
            win.m_key_pressed_callback(event);
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::window_close_event> callback) {
        m_window_close_callback = callback;//
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){
            const vulkan_window& win = get_window(window);
            win.m_window_close_callback(event::window_close_event{});
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::text_input_event> callback) {
        m_text_input_callback = callback;
        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
        {
            const vulkan_window& win = get_window(window);
            event::text_input_event event{ keycode };
            win.m_text_input_callback(event);
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::mouse_event> callback) {
        m_mouse_callback = callback;
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            const vulkan_window& win = get_window(window);
            const event::mouse_event event{button, action, mods};
            win.m_mouse_callback(event);
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::scroll_event> callback) {
        m_scroll_callback = callback;
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            const vulkan_window& win = get_window(window);
            const event::scroll_event event{xOffset, yOffset};
            win.m_scroll_callback(event);
        });
    }

    void vulkan_window::on(EventCallbackFnT<event::cursor_position_changed_event> callback) {
        m_cursor_changed_callback = callback;
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            const vulkan_window& win = get_window(window);
            const event::cursor_position_changed_event event{xPos, yPos};
            win.m_cursor_changed_callback(event);
        });
    }
}
