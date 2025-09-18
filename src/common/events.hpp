#pragma once

namespace jade::event {
    struct window_close_event {};

    struct window_resize_event {
        int width;
        int height;
    };

    // TODO: Consider adding a custom enum for keys and mouse codes rather than using the glfw ones
    struct key_pressed_event {
        int key;
        int scancode;
        int action;
        int mods;
    };

    struct text_input_event {
        unsigned int keycode;
    };

    struct mouse_event {
        int button;
        int action;
        int mods;
    };

    struct scroll_event {
        double x_offset;
        double y_offset;
    };

    struct cursor_position_changed_event {
        double x_position;
        double y_position;
    };
}
