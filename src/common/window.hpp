#pragma once

#include <functional>
#include <string>
#include <cstdint>
#include <utility>

#include "events.hpp"
#include "glm/vec2.hpp"

namespace jade
{
    template<typename EventT>
    using EventCallbackFnT = std::function<void(EventT)>;

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

        virtual void on(EventCallbackFnT<event::window_resize_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::key_pressed_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::window_close_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::text_input_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::mouse_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::scroll_event> callback) = 0;
        virtual void on(EventCallbackFnT<event::cursor_position_changed_event> callback) = 0;

    protected:
        window_settings m_settings;
        WindowBaseT* m_window;
        EventCallbackFnT<event::window_resize_event> m_window_resize_callback;
        EventCallbackFnT<event::key_pressed_event> m_key_pressed_callback;
        EventCallbackFnT<event::window_close_event> m_window_close_callback;
        EventCallbackFnT<event::text_input_event> m_text_input_callback;
        EventCallbackFnT<event::mouse_event> m_mouse_callback;
        EventCallbackFnT<event::scroll_event> m_scroll_callback;
        EventCallbackFnT<event::cursor_position_changed_event> m_cursor_changed_callback;
    };
}
