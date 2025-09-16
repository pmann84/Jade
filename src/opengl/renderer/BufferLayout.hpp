#pragma once

#include "ShaderCommon.hpp"

#include <string>
#include <vector>

namespace jade
{
    struct BufferElement
    {
        std::string name;
        ShaderDataType type;
        uint32_t size;
        size_t offset;
        bool normalized;

        BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
                : name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized)
        {
        }

        uint32_t componentCount() const
        {
            switch (type)
            {
                case ShaderDataType::Float:   return 1;
                case ShaderDataType::Float2:  return 2;
                case ShaderDataType::Float3:  return 3;
                case ShaderDataType::Float4:  return 4;
                case ShaderDataType::Mat3:    return 3; // 3* float3
                case ShaderDataType::Mat4:    return 4; // 4* float4
                case ShaderDataType::Int:     return 1;
                case ShaderDataType::Int2:    return 2;
                case ShaderDataType::Int3:    return 3;
                case ShaderDataType::Int4:    return 4;
                case ShaderDataType::Bool:    return 1;
            }
            return 0;
        }
    };

    class BufferLayout
    {
    public:
        BufferLayout() = default;
        BufferLayout(std::initializer_list<BufferElement> elements);

        uint32_t stride() const { return m_stride; }
        const std::vector<BufferElement>& elements() const { return m_elements; }

        std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return m_elements.cbegin(); }
        std::vector<BufferElement>::const_iterator end() const { return m_elements.cend(); }

    private:
        void CalculateOffsetsAndStride();

    private:
        std::vector<BufferElement> m_elements;
        uint32_t m_stride = 0;
    };
}