#include "Shader.hpp"

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

#include <fstream>
#include <iostream>

namespace gfxlib
{
    Shader::Shader(const std::filesystem::path &vertexShader, const std::filesystem::path &fragmentShader)
            : m_vertexPath(vertexShader), m_fragmentPath(fragmentShader)
    {
        m_vertexBinarySrc = loadShader(vertexShader);
        m_fragmentBinarySrc = loadShader(fragmentShader);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_id);
    }

    std::vector<char> Shader::loadShader(const std::filesystem::path &shader)
    {
        std::ifstream shaderFile;
        shaderFile.open(shader, std::ios::binary | std::ios::ate);
        if (shaderFile.is_open())
        {
            size_t size = shaderFile.tellg();
            shaderFile.seekg(0, std::ios::beg);
            char* buffer = new char[size];
            shaderFile.read(buffer, size);
            std::vector<char> data(buffer, buffer + size);
            return data;
        }
        else
        {
            std::cerr << "Could not open " << shader << std::endl;
            return std::vector<char>();
        }
    }

    void Shader::createProgram()
    {
        GLuint program = glCreateProgram();

        std::vector<GLuint> shaderIds;

        {
            auto spirv = m_vertexBinarySrc;
            GLuint shaderID = shaderIds.emplace_back(glCreateShader(GL_VERTEX_SHADER));
            glShaderBinary(1, &shaderID, GL_SHADER_BINARY_FORMAT_SPIR_V, spirv.data(), spirv.size() * sizeof(uint32_t));
            glSpecializeShader(shaderID, "main", 0, nullptr, nullptr);
            glAttachShader(program, shaderID);
        }

        {
            auto spirv = m_fragmentBinarySrc;
            GLuint shaderID = shaderIds.emplace_back(glCreateShader(GL_FRAGMENT_SHADER));
            glShaderBinary(1, &shaderID, GL_SHADER_BINARY_FORMAT_SPIR_V, spirv.data(), spirv.size() * sizeof(uint32_t));
            glSpecializeShader(shaderID, "main", 0, nullptr, nullptr);
            glAttachShader(program, shaderID);
        }

        glLinkProgram(program);

        GLint isLinked;
        glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());
            std::cerr << "Failed to link Shader: " << m_vertexPath << "/" << m_fragmentPath << ". " << infoLog.data() << std::endl;

            glDeleteProgram(program);

            for (auto id : shaderIds)
            {
                glDeleteShader(id);
            }
        }

        for (auto id : shaderIds)
        {
            glDetachShader(program, id);
            glDeleteShader(id);
        }

        m_id = program;
    }

    void Shader::bind() const
    {
        glUseProgram(m_id);
    }

    void Shader::unbind() const
    {
        glUseProgram(0);
    }

    void Shader::setInt(const std::string &name, int value)
    {
        uploadUniformInt(name, value);
    }

    void Shader::setIntArray(const std::string &name, int *values, uint32_t count)
    {
        uploadUniformIntArray(name, values, count);
    }

    void Shader::setFloat(const std::string &name, float value)
    {
        uploadUniformFloat(name, value);
    }

    void Shader::setFloat2(const std::string &name, const glm::vec2 &value)
    {
        uploadUniformFloat2(name, value);
    }

    void Shader::setFloat3(const std::string &name, const glm::vec3 &value)
    {
        uploadUniformFloat3(name, value);
    }

    void Shader::setFloat4(const std::string &name, const glm::vec4 &value)
    {
        uploadUniformFloat4(name, value);
    }

    void Shader::setMat4(const std::string &name, const glm::mat4 &value)
    {
        uploadUniformMat4(name, value);
    }

    void Shader::uploadUniformInt(const std::string &name, int value)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform1i(location, value);
    }

    void Shader::uploadUniformIntArray(const std::string &name, int *values, uint32_t count)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform1iv(location, count, values);
    }

    void Shader::uploadUniformFloat(const std::string &name, float value)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform1f(location, value);
    }

    void Shader::uploadUniformFloat2(const std::string &name, const glm::vec2 &value)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform2f(location, value.x, value.y);
    }

    void Shader::uploadUniformFloat3(const std::string &name, const glm::vec3 &value)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform3f(location, value.x, value.y, value.z);
    }

    void Shader::uploadUniformFloat4(const std::string &name, const glm::vec4 &value)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniform4f(location, value.x, value.y, value.z, value.w);
    }

    void Shader::uploadUniformMat3(const std::string &name, const glm::mat3 &matrix)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Shader::uploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
    {
        GLint location = glGetUniformLocation(m_id, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}