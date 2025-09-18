#pragma once

#include "RendererStatistics.hpp"
#include "RenderApi.hpp"
#include <glm/glm.hpp>

namespace jade
{
    struct RendererData
    {
        glm::vec4 QuadVertexPositions[4];
        uint32_t QuadIndices[6];
    };
    static RendererData sData;

    struct QuadVertex
    {
        glm::vec3 Position;
        glm::vec4 Color;
    };

    class Renderer
    {
    public:
        Renderer();

        void setView(glm::mat4 viewProjection)
        {
            m_viewProjection = viewProjection;
        }

        void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
        void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
        void DrawCircle();
        void DrawString();
        void DrawLine();
        void DrawTriangle();

    private:
        RendererStatistics m_stats;
        glm::mat4 m_viewProjection;
    };
}