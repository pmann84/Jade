#pragma once

#include "IndexBuffer.hpp"
#include "VertexBuffer.hpp"

#include <memory>

namespace jade
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        void unbind() const;

        void addVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);
        void setIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer);

        const std::vector<std::shared_ptr<VertexBuffer>>& vertexBuffers() const;
        const std::shared_ptr<IndexBuffer>& indexBuffer() const;

    private:
        uint32_t m_id;
        uint32_t m_vertexBufferIndex = 0;
        std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
    };
}