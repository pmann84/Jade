#include <memory>
#include "ApplicationBase.hpp"

class BasicApp : public gfxlib::ApplicationBase {
public:
    explicit BasicApp(gfxlib::WindowSettings settings) : gfxlib::ApplicationBase(settings) {}

    void OnUpdate(float ts) override
    {
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

//    void OnWindowClose(const WindowCloseEvent &event) override
//    {
//        ApplicationBase::OnWindowClose(event);
//    }
//
//    void OnCharPressed(const TextInputEvent&) override
//    {
//        ApplicationBase::on_char_press(keycode);
//    }
//
//    void OnMouseButton(const MouseEvent &event) override
//    {
//        ApplicationBase::OnMouseButton(event);
//    }
//
//    void OnScroll(const ScrollEvent &event) override
//    {
//        ApplicationBase::OnScroll(event);
//    }
//
//    void OnCursorPosChanged(const CursorPosChangedEvent &event) override
//    {
//        ApplicationBase::OnCursorPosChanged(event);
//    }

private:

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