#include "window/Window.hpp"

#include <windows.h>
#include <tchar.h>

#include <iostream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows desktop!");

    switch (message)
    {
//        case WM_PAINT:
//            hdc = BeginPaint(hWnd, &ps);
//
//            // Here your application is laid out.
//            // For this introduction, we just print out "Hello, Windows desktop!"
//            // in the top left corner.
//            TextOut(hdc,
//                    5, 5,
//                    greeting, _tcslen(greeting));
//            // End application specific layout section.
//
//            EndPaint(hWnd, &ps);
//            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    static TCHAR szTitle[] = _T("DirectX Window");
    static TCHAR szClassName[] = _T("DesktopWindow");

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInst;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szClassName;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        std::cerr << "Cannot register window!" << std::endl;
        return 1;
    }

    HWND hWnd = CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            szClassName,
            szTitle,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            500, 100,
            NULL,
            NULL,
            hInst,
            NULL
    );

    if (!hWnd)
    {
        std::cerr << "Cannot create window!" << std::endl;
        return 1;
    }

    ShowWindow(hWnd, cmdshow);
    UpdateWindow(hWnd);

    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;

//    jade::WindowSettings settings;
//    settings.width = 800;
//    settings.height = 600;
//    settings.title = "OpenGL Sandbox";
//    jade::Window window = jade::Window(settings);

    // Graphics context
//    jade::GraphicsContext ctx(window.handle());
//    ctx.initialise();
//    auto ctxInfo = ctx.info();
//    std::cout << "Vendor: " << ctxInfo.vendor << std::endl << "Renderer: " << ctxInfo.renderer << std::endl << "Version: " << ctxInfo.version << std::endl;

//    // Subscribe to some events
//    window.on([](WindowResizeEvent event){
//        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
//    });
//    window.on([](KeyPressedEvent event) {
//        std::cout << "Key pressed..." << event.key << std::endl;
//    });

//    while(!window.shouldClose())
//    {
//        ctx.pollEvents();
//        ctx.swapBuffers();
//    }
//    return 0;
}