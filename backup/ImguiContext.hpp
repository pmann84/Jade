#pragma once

#include "old_Window.hpp"

namespace jade
{
    class ImguiContext
    {
    public:
        explicit ImguiContext(old_Window& window);
        ~ImguiContext();

        void Initialise();
        void OnRenderStart();
        void OnRenderEnd();
        void Shutdown();

    private:
        old_Window &m_window;
    };
}