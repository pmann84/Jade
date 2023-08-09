#include <memory>
#include "ApplicationBase.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class BasicApp : public gfxlib::ApplicationBase {
public:
    explicit BasicApp(gfxlib::WindowSettings settings) : gfxlib::ApplicationBase(settings) {}

    void OnUpdate(float ts) override
    {
        glClearColor(0.8, 0.2, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OnUiRender() override
    {
    }

    void OnWindowResize(const WindowResizeEvent& event) override {
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    }

    void OnKeyPressed(const KeyPressedEvent& event) override {
        std::cout << "Key pressed..." << event.key << std::endl;
    }
};

int main()
{
    gfxlib::WindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "OpenGL Basic App";

    auto myApp = std::make_unique<BasicApp>(settings);
    myApp->start();

//    auto ctxInfo = ctx.info();
//    std::cout << "Vendor: " << ctxInfo.vendor << std::endl << "Renderer: " << ctxInfo.renderer << std::endl << "Version: " << ctxInfo.version << std::endl;
//
//    // Subscribe to some events
//    window.on([](WindowResizeEvent event){
//        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
//    });
//    window.on([](KeyPressedEvent event) {
//        std::cout << "Key pressed..." << event.key << std::endl;
//    });
//
//    // Initialise a render API
////    auto api = gfxlib::RenderApi();
////    api.initialise();
////    api.setClearColor({50 / 128.0, 168 / 128.0, 82 / 128.0, 1.0});
//
//    while(!window.shouldClose())
//    {
////        api.clear();
//        ctx.pollEvents();
//        ctx.swapBuffers();
//    }
    return 0;
}