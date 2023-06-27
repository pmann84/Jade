#include "GraphicsContext.hpp"

#include <glad/glad.h>

#include <iostream>

namespace gfxlib
{
    GraphicsContext::GraphicsContext(GLFWwindow *window) : m_window(window)
    {
        if (!m_window)
        {
            std::cout << "Window handle is null..." << std::endl;
        }
    }

    void GraphicsContext::initialise()
    {
        glfwMakeContextCurrent(m_window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
        {
            std::cout << "Failed to initialise GLAD!" << std::endl;
        }
    }

    void GraphicsContext::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    ContextInfo GraphicsContext::info()
    {
        std::string vendor(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        std::string renderer(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        std::string version(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        ContextInfo ctx{ vendor, renderer, version };
        return ctx;
    }

    void GraphicsContext::pollEvents()
    {
        glfwPollEvents();
    }
}