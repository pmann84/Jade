#pragma once

struct WindowCloseEvent {};

struct WindowResizeEvent
{
    int width;
    int height;
};

// TODO: Consider adding a custom enum for keys and mouse codes rather than using the glfw ones
struct KeyPressedEvent
{
    int key;
    int scancode;
    int action;
    int mods;
};

struct TextInputEvent
{
    unsigned int keycode;
};

struct MouseEvent
{
    int button;
    int action;
    int mods;
};

struct ScrollEvent
{
    double xOffset;
    double yOffset;
};

struct CursorPosChangedEvent
{
    double xPos;
    double yPos;
};