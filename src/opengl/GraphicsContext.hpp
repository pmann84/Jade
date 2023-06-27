#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <string>

namespace gfxlib
{
    struct ContextInfo
    {
        std::string vendor;
        std::string renderer;
        std::string version;
    };

    class GraphicsContext
    {
    public:
        GraphicsContext(GLFWwindow *window);

        void initialise();

        void swapBuffers();
        void pollEvents();

        ContextInfo info();

    private:
        GLFWwindow *m_window;
    };
}