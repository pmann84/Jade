#pragma once
#include "events.hpp"

namespace jade {
    class layer {
    public:
        virtual ~layer() = default;

        virtual void on_event(event::event_base& ev) {}
        virtual void on_update(float ts) {}
        virtual void on_render() {}
    };
}
