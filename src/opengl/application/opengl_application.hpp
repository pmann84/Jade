#pragma once

#include "application.hpp"
#include "opengl_window.hpp"

namespace jade {
    class opengl_application : public application<opengl_window> {
    public:
        explicit opengl_application(application_settings settings)
            : application(std::move(settings)) {
        }
        ~opengl_application() override = default;

        float get_time() override;
        void poll_events() override;
    };
}
