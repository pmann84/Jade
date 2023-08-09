#include "ImguiContext.hpp"

#include <imgui.h>
#include "./bindings/imgui_impl_glfw.h"
#include "./bindings/imgui_impl_opengl3.h"

namespace gfxlib
{
    ImguiContext::ImguiContext(Window& window): m_window(window)
    {
        Initialise();
    }

    ImguiContext::~ImguiContext()
    {
        Shutdown();
    }

    void ImguiContext::Initialise()
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//      io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
//      io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_window.handle(), true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImguiContext::Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImguiContext::OnRenderStart()
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImguiContext::OnRenderEnd()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
//    ImGuiIO &io = ImGui::GetIO();
//    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
//        GLFWwindow* backup_current_context = glfwGetCurrentContext();
//        ImGui::UpdatePlatformWindows();
//        ImGui::RenderPlatformWindowsDefault();
//        glfwMakeContextCurrent(backup_current_context);
//    }
    }
}