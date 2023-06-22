#include "IndexBuffer.hpp"

#include <glad/glad.h>

namespace gfxlib
{
    IndexBuffer::IndexBuffer(uint32_t *indices, uint32_t count): m_count(count)
    {
        glCreateBuffers(1, &m_id);

        // GL_ELEMENT_ARRAY_BUFFER is not valid without an actively bound VAO
        // Binding with GL_ARRAY_BUFFER allows the data to be loaded regardless of VAO state.
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_id);
    }

    void IndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void IndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}