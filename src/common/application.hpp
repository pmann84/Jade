#pragma once

#include "layer.hpp"
#include "window.hpp"

#include <memory>
#include <string>
#include <vector>
#include <type_traits>

#include "glm/ext/scalar_common.hpp"


namespace jade {
    struct application_settings
    {
        std::string name;
        window_settings window_settings;
    };

    template <typename WindowT>
    // requires(std::is_base_of_v<window, WindowT>)
    class application {
    public:
        explicit application(application_settings settings)
            : m_settings(std::move(settings))
            , m_window(std::make_shared<WindowT>(settings.window_settings)) {
            m_window->on([this](event::window_resize_event event){
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::key_pressed_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::window_close_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::text_input_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::mouse_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::scroll_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });
            m_window->on([this](event::cursor_position_changed_event event) {
                for (const auto& layer : m_layer_stack) {
                    layer->on_event(event);
                }
            });

        }
        virtual ~application() = default;

        virtual float get_time() = 0;
        virtual void poll_events() = 0;

        template<typename LayerT>
        requires(std::is_base_of_v<layer, LayerT>)
        void push_layer() {
            m_layer_stack.push_back(std::make_unique<LayerT>());
        }

        void start() {
            m_running = true;

            float last_time = get_time();

            while (m_running) {
                poll_events();

                if (m_window->should_close()) {
                    stop();
                    break;
                }

                const auto current_time = get_time();
                const float timestep = glm::clamp(current_time - last_time, 0.001f, 0.1f);
                last_time = current_time;

                for (const auto& layer : m_layer_stack) {
                    layer->on_update(timestep);
                }

                for (const auto& layer : m_layer_stack) {
                    layer->on_render();
                }

                m_window->update();
            }

        }
        void stop() {
            m_running = false;
        }

    protected:
        application_settings m_settings;
        std::vector<std::unique_ptr<layer>> m_layer_stack;
        std::shared_ptr<WindowT> m_window;
        bool m_running = false;
    };
}
