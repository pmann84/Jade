#pragma once

#include "Events.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <functional>
#include <iostream>

namespace gfxlib
{
    template<typename EventT>
    using EventCallbackFnT = std::function<void(EventT)>;

    struct WindowSettings
    {
        std::string title;
        uint32_t width;
        uint32_t height;
    };

    class Window
    {
    public:
        Window(WindowSettings settings);
        ~Window();

        void onUpdate() const;
        bool shouldClose() const;
        GLFWwindow* handle() const;

        glm::vec2 getCursorPosition();

        // TODO: Add macro that adds the function and the member
        void on(EventCallbackFnT<WindowResizeEvent> callback);
        void on(EventCallbackFnT<KeyPressedEvent> callback);
        void on(EventCallbackFnT<WindowCloseEvent> callback);
        void on(EventCallbackFnT<TextInputEvent> callback);
        void on(EventCallbackFnT<MouseEvent> callback);
        void on(EventCallbackFnT<ScrollEvent> callback);
        void on(EventCallbackFnT<CursorPosChangedEvent> callback);

    private:
        void initialise();
        void shutdown();

    private:
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;
        GLFWwindow* m_window;

        // Callbacks
        EventCallbackFnT<WindowResizeEvent> m_windowResizeCallback;
        EventCallbackFnT<KeyPressedEvent> m_keyPressedCallback;
        EventCallbackFnT<WindowCloseEvent> m_windowCloseCallback;
        EventCallbackFnT<TextInputEvent> m_textInputCallback;
        EventCallbackFnT<MouseEvent> m_mouseCallback;
        EventCallbackFnT<ScrollEvent> m_scrollCallback;
        EventCallbackFnT<CursorPosChangedEvent> m_cursorChangedCallback;
    };
}