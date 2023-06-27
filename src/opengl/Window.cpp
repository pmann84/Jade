#include "Window.hpp"

#include <glad/glad.h>

namespace gfxlib
{
    static void error_callback(int error, const char* description)
    {
//        logging::error("GLFW Error ({0}): {1}", error, description);
    }

    Window::Window(WindowSettings settings): m_width(settings.width), m_height(settings.height), m_title(settings.title)
    {
        initialise();
    }

    Window::~Window()
    {
        shutdown();
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::initialise()
    {
        if (!glfwInit())
        {
            // Initialization failed
//            logging::critical("GLFW Initialisation failed.");
            return;
        }

        glfwSetErrorCallback(error_callback);

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_window)
        {
            // Window or context creation failed
//            logging::critical("GLFW Window creation failed.");
            glfwTerminate();
            return;
        }

        glfwSetWindowUserPointer(m_window, this);

        glfwMakeContextCurrent(m_window);
    }

    void Window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    glm::vec2 Window::getCursorPosition()
    {
        double xPos, yPos;
        glfwGetCursorPos(m_window, &xPos, &yPos);
        return glm::vec2(xPos, yPos);
    }

    void Window::on(EventCallbackFnT<WindowResizeEvent> callback)
    {
        m_windowResizeCallback = callback;
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height){
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            win.m_width = width;
            win.m_height = height;
            WindowResizeEvent event { width, height };
            win.m_windowResizeCallback(event);
        });
    }

    void Window::on(EventCallbackFnT<KeyPressedEvent> callback)
    {
        m_keyPressedCallback = callback;
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            KeyPressedEvent event { key, scancode, action, mods };
            win.m_keyPressedCallback(event);
        });
    }

    void Window::on(EventCallbackFnT<WindowCloseEvent> callback)
    {
        m_windowCloseCallback = callback;//
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            win.m_windowCloseCallback(WindowCloseEvent{});
        });

    }

    void Window::on(EventCallbackFnT<TextInputEvent> callback)
    {
        m_textInputCallback = callback;
        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
        {
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            TextInputEvent event{ keycode };
            win.m_textInputCallback(event);
        });
    }

    void Window::on(EventCallbackFnT<MouseEvent> callback)
    {
        m_mouseCallback = callback;
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            MouseEvent event{button, action, mods};
            win.m_mouseCallback(event);
        });
    }

    void Window::on(EventCallbackFnT<ScrollEvent> callback)
    {
        m_scrollCallback = callback;
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            ScrollEvent event{xOffset, yOffset};
            win.m_scrollCallback(event);
        });
    }

    void Window::on(EventCallbackFnT<CursorPosChangedEvent> callback)
    {
        m_cursorChangedCallback = callback;
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            Window& win = *(Window*)glfwGetWindowUserPointer(window);
            CursorPosChangedEvent event{xPos, yPos};
            win.m_cursorChangedCallback(event);
        });
    }

    GLFWwindow *Window::handle() const
    {
        return m_window;
    }
}