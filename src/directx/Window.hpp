#pragma once

#include <windows.h>

#include <string>

namespace jade
{
    struct WindowSettings
    {
        std::string title;
        uint32_t width;
        uint32_t height;
    };

    class Window
    {
    public:
        Window(HINSTANCE hInst, int cmdShow, WindowSettings settings);
        ~Window();

    private:
        void initialise(HINSTANCE hInst, int cmdShow);
        void shutdown();

        LRESULT CALLBACK ProcessEvents(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    private:
        std::string m_title;
        uint32_t m_width;
        uint32_t m_height;
    };
}