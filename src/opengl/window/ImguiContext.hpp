#pragma once

#include "Window.hpp"

namespace jade
{
    class ImguiContext
    {
    public:
        explicit ImguiContext(Window& window);
        ~ImguiContext();

        void Initialise();
        void OnRenderStart();
        void OnRenderEnd();
        void Shutdown();

    private:
        Window &m_window;
    };
}