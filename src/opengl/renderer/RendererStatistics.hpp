#pragma once

#include <cstdint>

namespace jade
{
    struct RendererStatistics
    {
        uint32_t DrawCalls = 0;
        uint32_t QuadCount = 0;
        uint32_t TriCount = 0;

        [[nodiscard]] uint32_t VertexCount() const { return QuadCount * 4 + TriCount * 3; }
        [[nodiscard]] uint32_t IndexCount() const { return QuadCount * 6 + TriCount * 3; }
    };
}