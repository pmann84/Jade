#pragma once
#include "events.hpp"

namespace jade {
    class layer {
    public:
        virtual ~layer() = default;

        virtual void on_update(float ts) {}
        virtual void on_render() {}

        virtual void on(event::window_resize_event event) {}
        virtual void on(event::key_pressed_event event) {}
        virtual void on(event::window_close_event event) {}
        virtual void on(event::text_input_event event) {}
        virtual void on(event::mouse_event event) {}
        virtual void on(event::scroll_event event) {}
        virtual void on(event::cursor_position_changed_event event) {}
    };
}
