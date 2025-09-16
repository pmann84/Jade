#pragma once

#include "glm/glm.hpp"

namespace jade
{
    class Camera
    {
    public:
        Camera() = default;
        Camera(float fov, float aspectRatio, float nearClip, float farClip);

        const glm::mat4& projection() const;

    protected:
        float m_fov = 45.0f;
        float m_aspectRatio = 1.778f;
        float m_nearClip = 0.1f;
        float m_farClip = 1000.0f;

        glm::mat4 m_projection = glm::mat4(1.0f);

//        glm::mat4 m_ViewMatrix;
//        glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
//        glm::vec3 m_FocalPoint = { 0.0f, 0.0f, 0.0f };
//
//        glm::vec2 m_InitialMousePosition = { 0.0f, 0.0f };
//
//        float m_Distance = 10.0f;
//        float m_Pitch = 0.0f, m_Yaw = 0.0f;
//
//        float m_ViewportWidth = 1280, m_ViewportHeight = 720;
    };
}