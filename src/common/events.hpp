#pragma once

namespace jade::event {
    struct event_base {};

    struct window_close_event : event_base {};

    struct window_resize_event : event_base {
        int width;
        int height;
    };

    // TODO: Consider adding a custom enum for keys and mouse codes rather than using the glfw ones
    struct key_pressed_event : event_base {
        int key;
        int scancode;
        int action;
        int mods;
    };

    struct text_input_event : event_base  {
        unsigned int keycode;
    };

    struct mouse_event : event_base  {
        int button;
        int action;
        int mods;
    };

    struct scroll_event : event_base  {
        double x_offset;
        double y_offset;
    };

    struct cursor_position_changed_event : event_base  {
        double x_position;
        double y_position;
    };
}
