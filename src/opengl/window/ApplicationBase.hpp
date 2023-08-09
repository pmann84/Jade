#pragma once

#include "Window.hpp"
#include "GraphicsContext.hpp"
#include "TimeStepper.hpp"
#include "ImguiContext.hpp"

#include <cstdint>
#include <string>

namespace gfxlib {
    class ApplicationBase
    {
    public:
        explicit ApplicationBase(WindowSettings settings)
                : m_data(settings)
                , m_window(m_data)
                , m_context(m_window.handle())
                , m_uiContext(m_window)
        {
            m_context.initialise();

            m_window.on([this](WindowResizeEvent event){
                OnWindowResize(event);
            });
            m_window.on([this](KeyPressedEvent event) {
                OnKeyPressed(event);
            });
        }

        ~ApplicationBase() {
        }

        virtual void OnUpdate(float ts) = 0;
        virtual void OnUiRender() = 0;

        //    virtual void on_error(int error, const char* description) = 0;
        virtual void OnKeyPressed(const KeyPressedEvent&) {}
        virtual void OnWindowClose(const WindowCloseEvent&) {}
        virtual void OnWindowResize(const WindowResizeEvent&) {}
        virtual void OnCharPressed(const TextInputEvent&) {}
        virtual void OnMouseButton(const MouseEvent&) {}
        virtual void OnScroll(const ScrollEvent&) {}
        virtual void OnCursorPosChanged(const CursorPosChangedEvent&) {}

        void start() {
            while(!m_window.shouldClose())
            {
                // Poll for events
                m_context.pollEvents();

                // Initialise new frame
                m_uiContext.OnRenderStart();

                // Update client code every frame
                OnUpdate(m_time_step.get());

                // UI rendering
                OnUiRender();

                // Finish imgui rendering
                m_uiContext.OnRenderEnd();

                // Do other bits here
                m_context.swapBuffers();
                m_time_step.update();
            }
        }

    protected:
        WindowSettings m_data;
        Window m_window;
        GraphicsContext m_context;
        ImguiContext m_uiContext;

    private:
        TimeStepper m_time_step;
    };
}

