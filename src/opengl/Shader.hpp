#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <filesystem>

namespace gfxlib
{
    class Shader
    {
    public:
        Shader(const std::filesystem::path& vertexShader, std::filesystem::path& fragmentShader);
        ~Shader();

        void bind() const;
        void unbind() const;

        void setInt(const std::string& name, int value);
        void setIntArray(const std::string& name, int* values, uint32_t count);
        void setFloat(const std::string& name, float value);
        void setFloat2(const std::string& name, const glm::vec2& value);
        void setFloat3(const std::string& name, const glm::vec3& value);
        void setFloat4(const std::string& name, const glm::vec4& value);
        void setMat4(const std::string& name, const glm::mat4& value);

    private:
        std::vector<char> loadShader(const std::filesystem::path& shader);
        void createProgram();

        void uploadUniformInt(const std::string& name, int value);
        void uploadUniformIntArray(const std::string& name, int* values, uint32_t count);
        void uploadUniformFloat(const std::string& name, float value);
        void uploadUniformFloat2(const std::string& name, const glm::vec2& value);
        void uploadUniformFloat3(const std::string& name, const glm::vec3& value);
        void uploadUniformFloat4(const std::string& name, const glm::vec4& value);
        void uploadUniformMat3(const std::string& name, const glm::mat3& matrix);
        void uploadUniformMat4(const std::string& name, const glm::mat4& matrix);

    private:
        uint32_t m_id;
        std::filesystem::path m_vertexPath;
        std::vector<char> m_vertexBinarySrc;

        std::filesystem::path m_fragmentPath;
        std::vector<char> m_fragmentBinarySrc;
    };
}