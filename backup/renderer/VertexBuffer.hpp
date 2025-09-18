#pragma once

#include "BufferLayout.hpp"

#include <cstdint>

namespace jade
{
    class VertexBuffer
    {
    public:
        VertexBuffer(uint32_t size);
        VertexBuffer(float *vertices, uint32_t size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

        void setData(const void *data, uint32_t size);

        const BufferLayout& layout() const { return m_layout; }
        void layout(const BufferLayout& layout) { m_layout = layout; }
    private:
        uint32_t m_id;
        BufferLayout m_layout;
    };
}