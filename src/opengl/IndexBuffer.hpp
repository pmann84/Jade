#pragma once

#include <cstdint>

namespace gfxlib
{
    class IndexBuffer
    {
    public:
        IndexBuffer(uint32_t *indices, uint32_t count);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        virtual uint32_t count() const { return m_count; }
    private:
        uint32_t m_id;
        uint32_t m_count;
    };
}