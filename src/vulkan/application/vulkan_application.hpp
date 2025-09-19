#pragma once

#include "application.hpp"
#include "vulkan_window.hpp"

namespace jade {
    class vulkan_application : public application<vulkan_window> {
    public:
        explicit vulkan_application(application_settings settings);
        ~vulkan_application() override = default;

        float get_time() override;
        void poll_events() override;
    };
}
