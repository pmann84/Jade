#pragma once

#include "VertexArray.hpp"

#include "glm/glm.hpp"

#include <cstdint>
#include <memory>

namespace gfxlib
{
    class RenderApi
    {
    public:
        void initialise();
        void clear();

        void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
        void setClearColor(const glm::vec4& color);
        void setLineWidth(float width);

        void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount = 0);
        void drawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount);
    };
}