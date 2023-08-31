#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class TimeStepper
{
public:
    [[nodiscard]] float get() const
    {
        return m_time_step;
    }

    void update()
    {
        auto time = (float)glfwGetTime();
        m_frame_time = time - m_last_frame_time;
        m_time_step = glm::min<float>(m_frame_time, 0.0333f);
        m_last_frame_time = time;
    }

private:
    float m_time_step = 0.0f;
    float m_frame_time = 0.0f;
    float m_last_frame_time = 0.0f;
};
