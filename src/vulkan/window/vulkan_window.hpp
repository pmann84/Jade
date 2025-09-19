#pragma once

#include "window.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace jade {
    class vulkan_window final : public window<GLFWwindow> {
    public:
        explicit vulkan_window(window_settings settings);
        ~vulkan_window() override;
        [[nodiscard]] bool should_close() const override;

        [[maybe_unused]] glm::vec2 get_cursor_position() override;

        void on(EventCallbackFnT<event::window_resize_event> callback) override;
        void on(EventCallbackFnT<event::key_pressed_event> callback) override;
        void on(EventCallbackFnT<event::window_close_event> callback) override;
        void on(EventCallbackFnT<event::text_input_event> callback) override;
        void on(EventCallbackFnT<event::mouse_event> callback) override;
        void on(EventCallbackFnT<event::scroll_event> callback) override;
        void on(EventCallbackFnT<event::cursor_position_changed_event> callback) override;

    private:
        static vulkan_window& get_window(GLFWwindow* window);
    };
}
