#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <string>

namespace gfxlib
{
    using EventCallbackFnT = void();

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
        void onUpdate() const;
        bool shouldClose() const;

    private:
        void initialise();
        void shutdown();

    private:
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;
        EventCallbackFnT m_onCloseCallback;
        GLFWwindow* m_window;
    };
}