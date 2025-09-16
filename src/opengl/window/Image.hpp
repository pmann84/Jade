#pragma once

#include "glad/glad.h"

#include <cstdint>
#include <vector>

namespace jade {
    class Image
    {
    public:
        Image(uint32_t width, uint32_t height, GLenum format);
        void resize(uint32_t width, uint32_t height);

        [[nodiscard]] uint32_t width() const { return m_width; }
        [[nodiscard]] uint32_t height() const { return m_height; }
        [[nodiscard]] uint32_t id() const { return m_texture_id; }

        [[maybe_unused]] void setData(void *data) const;

    private:
        uint32_t m_width = 0;
        uint32_t m_height = 0;
        uint32_t m_texture_id;
        GLenum m_internal_format = GL_RGBA8;
        GLenum m_data_format = GL_RGBA;
    };
}
