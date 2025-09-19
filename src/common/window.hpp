#pragma once

#include "events.hpp"

#include <string>
#include <cstdint>
#include <utility>

#include "glm/vec2.hpp"

namespace jade
{
    struct window_settings
    {
        std::string title;
        uint32_t width = 1280;
        uint32_t height = 720;
        bool is_resizable = true;
        bool fullscreen = false;
        bool vsync = true;
    };

    template<typename WindowBaseT>
    class window
    {
    public:
        explicit window(window_settings settings) : m_settings(std::move(settings)), m_window(nullptr) {
        };
        virtual ~window() = default;

        [[nodiscard]] virtual bool should_close() const = 0;
        [[nodiscard]] virtual WindowBaseT* handle() const {
            return m_window;
        }
        [[maybe_unused]] virtual glm::vec2 get_cursor_position() = 0;
        virtual void update() = 0;

        virtual void on(event::EventCallbackFnT<event::window_resize_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::key_pressed_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::window_close_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::text_input_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::mouse_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::scroll_event> callback) = 0;
        virtual void on(event::EventCallbackFnT<event::cursor_position_changed_event> callback) = 0;

    protected:
        window_settings m_settings;
        WindowBaseT* m_window;
        event::EventCallbackFnT<event::window_resize_event> m_window_resize_callback;
        event::EventCallbackFnT<event::key_pressed_event> m_key_pressed_callback;
        event::EventCallbackFnT<event::window_close_event> m_window_close_callback;
        event::EventCallbackFnT<event::text_input_event> m_text_input_callback;
        event::EventCallbackFnT<event::mouse_event> m_mouse_callback;
        event::EventCallbackFnT<event::scroll_event> m_scroll_callback;
        event::EventCallbackFnT<event::cursor_position_changed_event> m_cursor_changed_callback;
    };
}
