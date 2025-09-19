#include <vulkan_window.hpp>
#include "events.hpp"
#include <iostream>

#include "window.hpp"

int main()
{
    jade::window_settings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "Simple Vulkan Window";
    jade::vulkan_window window = jade::vulkan_window(settings);

    // Subscribe to some events
    window.on([](jade::event::window_resize_event event){
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    });
    window.on([](jade::event::key_pressed_event event) {
        std::cout << "Key pressed..." << event.key << std::endl;
    });

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << extensionCount << " extensions supported\n";

    while(!window.should_close())
    {
        // glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window.handle());
    }
    return 0;
}
