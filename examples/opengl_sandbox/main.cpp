#include <Window.hpp>
#include <Events.hpp>
#include <RenderApi.hpp>

#include <iostream>
#include "GraphicsContext.hpp"

int main()
{
    gfxlib::WindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "OpenGL Sandbox";
    gfxlib::Window window = gfxlib::Window(settings);

    // Graphics context
    gfxlib::GraphicsContext ctx(window.handle());
    ctx.initialise();
    auto ctxInfo = ctx.info();
    std::cout << "Vendor: " << ctxInfo.vendor << std::endl << "Renderer: " << ctxInfo.renderer << std::endl << "Version: " << ctxInfo.version << std::endl;

    // Subscribe to some events
    window.on([](WindowResizeEvent event){
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    });
    window.on([](KeyPressedEvent event) {
        std::cout << "Key pressed..." << event.key << std::endl;
    });

    // Initialise a render API
    auto api = gfxlib::RenderApi();
    api.initialise();
    api.setClearColor({50 / 128.0, 168 / 128.0, 82 / 128.0, 1.0});

    while(!window.shouldClose())
    {
        api.clear();
        ctx.pollEvents();
        ctx.swapBuffers();
    }
    return 0;
}