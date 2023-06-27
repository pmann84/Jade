#include "VertexArray.hpp"

#include "ShaderCommon.hpp"

#include <glad/glad.h>

#include <iostream>

namespace gfxlib
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
            case ShaderDataType::Float:    return GL_FLOAT;
            case ShaderDataType::Float2:   return GL_FLOAT;
            case ShaderDataType::Float3:   return GL_FLOAT;
            case ShaderDataType::Float4:   return GL_FLOAT;
            case ShaderDataType::Mat3:     return GL_FLOAT;
            case ShaderDataType::Mat4:     return GL_FLOAT;
            case ShaderDataType::Int:      return GL_INT;
            case ShaderDataType::Int2:     return GL_INT;
            case ShaderDataType::Int3:     return GL_INT;
            case ShaderDataType::Int4:     return GL_INT;
        }
        return 0;
    }

    gfxlib::VertexArray::VertexArray()
    {
        glCreateVertexArrays(1, &m_id);
    }

    gfxlib::VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_id);
    }

    void gfxlib::VertexArray::bind() const
    {
        glBindVertexArray(m_id);
    }

    void gfxlib::VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

    void gfxlib::VertexArray::addVertexBuffer(const std::shared_ptr<gfxlib::VertexBuffer>& buffer)
    {
        if (buffer->layout().elements().size() == 0)
        {
            std::cout << "Vertex buffer has no layout" << std::endl;
        }

        bind();
        buffer->bind();

        const auto& layout = buffer->layout();
        for (const auto& element : layout)
        {
            switch (element.type)
            {
                case ShaderDataType::Float:
                case ShaderDataType::Float2:
                case ShaderDataType::Float3:
                case ShaderDataType::Float4:
                {
                    glEnableVertexAttribArray(m_vertexBufferIndex);
                    glVertexAttribPointer(m_vertexBufferIndex,
                                          element.componentCount(),
                                          ShaderDataTypeToOpenGLBaseType(element.type),
                                          element.normalized ? GL_TRUE : GL_FALSE,
                                          layout.stride(),
                                          (const void*)element.offset);
                    m_vertexBufferIndex++;
                    break;
                }
                case ShaderDataType::Int:
                case ShaderDataType::Int2:
                case ShaderDataType::Int3:
                case ShaderDataType::Int4:
                case ShaderDataType::Bool:
                {
                    glEnableVertexAttribArray(m_vertexBufferIndex);
                    glVertexAttribIPointer(m_vertexBufferIndex,
                                           element.componentCount(),
                                           ShaderDataTypeToOpenGLBaseType(element.type),
                                           layout.stride(),
                                           (const void*)element.offset);
                    m_vertexBufferIndex++;
                    break;
                }
                case ShaderDataType::Mat3:
                case ShaderDataType::Mat4:
                {
                    uint8_t count = element.componentCount();
                    for (uint8_t i = 0; i < count; i++)
                    {
                        glEnableVertexAttribArray(m_vertexBufferIndex);
                        glVertexAttribPointer(m_vertexBufferIndex,
                                              count,
                                              ShaderDataTypeToOpenGLBaseType(element.type),
                                              element.normalized ? GL_TRUE : GL_FALSE,
                                              layout.stride(),
                                              (const void*)(element.offset + sizeof(float) * count * i));
                        glVertexAttribDivisor(m_vertexBufferIndex, 1);
                        m_vertexBufferIndex++;
                    }
                    break;
                }
                default:
                    std::cout << "Unknown Shader Data Type" << std::endl;
            }
        }

        m_vertexBuffers.push_back(buffer);
    }

    void gfxlib::VertexArray::setIndexBuffer(const std::shared_ptr<gfxlib::IndexBuffer> &buffer)
    {
        glBindVertexArray(m_id);
        buffer->bind();

        m_indexBuffer = buffer;
    }

    const std::vector<std::shared_ptr<gfxlib::VertexBuffer>> &gfxlib::VertexArray::vertexBuffers() const
    {
        return m_vertexBuffers;
    }

    const std::shared_ptr<gfxlib::IndexBuffer> &gfxlib::VertexArray::indexBuffer() const
    {
        return m_indexBuffer;
    }
}