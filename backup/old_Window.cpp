#include "old_Window.hpp"

namespace jade
{
    static void error_callback(int error, const char* description)
    {
//        logging::error("GLFW Error ({0}): {1}", error, description);
    }

    old_Window::old_Window(const WindowSettings& settings): m_width(settings.width), m_height(settings.height), m_title(settings.title)
    {
        initialise();
    }

    old_Window::~old_Window()
    {
        shutdown();
    }

    bool old_Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void old_Window::initialise()
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

    void old_Window::shutdown()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    [[maybe_unused]] glm::vec2 old_Window::getCursorPosition()
    {
        double xPos, yPos;
        glfwGetCursorPos(m_window, &xPos, &yPos);
        return {xPos, yPos};
    }

    void old_Window::on(EventCallbackFnT<WindowResizeEvent> callback)
    {
        m_windowResizeCallback = callback;
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height){
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            win.m_width = width;
            win.m_height = height;
            WindowResizeEvent event { width, height };
            win.m_windowResizeCallback(event);
        });
    }

    void old_Window::on(EventCallbackFnT<KeyPressedEvent> callback)
    {
        m_keyPressedCallback = callback;
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            KeyPressedEvent event { key, scancode, action, mods };
            win.m_keyPressedCallback(event);
        });
    }

    void old_Window::on(EventCallbackFnT<WindowCloseEvent> callback)
    {
        m_windowCloseCallback = callback;//
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            win.m_windowCloseCallback(WindowCloseEvent{});
        });

    }

    void old_Window::on(EventCallbackFnT<TextInputEvent> callback)
    {
        m_textInputCallback = callback;
        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
        {
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            TextInputEvent event{ keycode };
            win.m_textInputCallback(event);
        });
    }

    void old_Window::on(EventCallbackFnT<MouseEvent> callback)
    {
        m_mouseCallback = callback;
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            MouseEvent event{button, action, mods};
            win.m_mouseCallback(event);
        });
    }

    void old_Window::on(EventCallbackFnT<ScrollEvent> callback)
    {
        m_scrollCallback = callback;
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            ScrollEvent event{xOffset, yOffset};
            win.m_scrollCallback(event);
        });
    }

    void old_Window::on(EventCallbackFnT<CursorPosChangedEvent> callback)
    {
        m_cursorChangedCallback = callback;
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            old_Window& win = *(old_Window*)glfwGetWindowUserPointer(window);
            CursorPosChangedEvent event{xPos, yPos};
            win.m_cursorChangedCallback(event);
        });
    }

    GLFWwindow *old_Window::handle() const
    {
        return m_window;
    }
}