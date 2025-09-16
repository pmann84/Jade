#include <memory>
#include "ApplicationBase.hpp"
#include <Renderer.hpp>
#include <imgui.h>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>

glm::vec4 DefaultColour = glm::vec4(0.3, 0.7, 0.4, 1.0);

class BasicApp : public jade::ApplicationBase {
public:
    explicit BasicApp(jade::WindowSettings settings) : jade::ApplicationBase(settings) {
        jade::RenderApi::initialise();
        jade::RenderApi::setClearColor(DefaultColour);
    }

    void OnUpdate(float ts) override
    {
        jade::RenderApi::clear();

        m_renderer.DrawQuad(
            glm::vec3(0.0, 0.0, 0.0),
            glm::vec2(1.0, 1.0),
            glm::vec4(0.0, 1.0, 0.0, 1.0)
        );

    }

    void OnUiRender() override
    {
        ImGui::Begin("Hardware Info");
        ImGui::Text("Vendor: %s", m_context.info().vendor.c_str());
        ImGui::Text("Renderer: %s", m_context.info().renderer.c_str());
        ImGui::Text("Version: %s", m_context.info().version.c_str());
        ImGui::End();
    }

    void OnWindowResize(const WindowResizeEvent& event) override {
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    }

    void OnKeyPressed(const KeyPressedEvent& event) override {
        std::cout << "Key pressed..." << event.key << std::endl;
    }

    std::string getInfo() {
        auto ctxInfo = m_context.info();
        std::stringstream ss;
        ss << "Vendor: " << ctxInfo.vendor << std::endl << "Renderer: " << ctxInfo.renderer << std::endl << "Version: " << ctxInfo.version << std::endl;
        return ss.str();
    }

private:
    jade::Renderer m_renderer;
};

int main()
{
    jade::WindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "OpenGL Basic App";
// hello
    auto myApp = std::make_unique<BasicApp>(settings);
    myApp->start();

    return 0;
}