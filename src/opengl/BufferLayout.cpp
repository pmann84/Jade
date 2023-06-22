#include "BufferLayout.hpp"

namespace gfxlib
{
    BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements) : m_elements(elements)
    {
        CalculateOffsetsAndStride();
    }

    void BufferLayout::CalculateOffsetsAndStride()
    {
        size_t offset = 0;
        m_stride = 0;
        for (auto& element : m_elements)
        {
            element.offset = offset;
            offset += element.size;
            m_stride += element.size;
        }
    }
}