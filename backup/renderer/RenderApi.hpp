#pragma once

#include "VertexArray.hpp"

#include "glm/glm.hpp"

#include <cstdint>
#include <memory>

namespace jade
{
    class RenderApi
    {
    public:
        static void initialise();
        static void clear();

        static void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
        static void setClearColor(const glm::vec4& color);
        static void setLineWidth(float width);

        static void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0);
        static void drawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount);
    };
}