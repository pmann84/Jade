#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace gfxlib {
    Renderer::Renderer()
    {
        // Setup Quad Vertices
        sData.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
        sData.QuadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
        sData.QuadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
        sData.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };

        // Set up the indices
        sData.QuadIndices[0] = 0;
        sData.QuadIndices[1] = 1;
        sData.QuadIndices[2] = 2;
        sData.QuadIndices[3] = 2;
        sData.QuadIndices[4] = 3;
        sData.QuadIndices[5] = 0;
    }

    void Renderer::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                            * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });

        DrawQuad(transform, color);
    }

    void Renderer::DrawQuad(const glm::mat4& transform, const glm::vec4& color)
    {
        constexpr size_t quadVertexCount = 4;
        auto quadVertexArray = std::make_shared<VertexArray>();
        auto quadVertexBuffer = std::make_shared<VertexBuffer>(4 * sizeof(QuadVertex));
        quadVertexBuffer->layout({
               { ShaderDataType::Float3, "a_Position" },
               { ShaderDataType::Float4, "a_Color"    }
        });
        quadVertexArray->addVertexBuffer(quadVertexBuffer);
        auto quadShader = std::make_shared<Shader>("shaders/quad.vert.spv", "shaders/quad.frag.spv");
        quadShader->setMat4("u_ViewProjection", m_viewProjection);

        auto quadIndexBuffer = std::make_shared<IndexBuffer>(sData.QuadIndices, 6);
        quadVertexArray->setIndexBuffer(quadIndexBuffer);

        // Create indices and vertices
        QuadVertex quadVertices[quadVertexCount];

        // Populate the quad vertices
        for (size_t i = 0; i < quadVertexCount; i++)
        {
            auto vertex = quadVertices[i];
            vertex.Position = transform * sData.QuadVertexPositions[i];
            vertex.Color = color;
        }

//            uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.QuadVertexBufferPtr - (uint8_t*)s_Data.QuadVertexBufferBase);
//            s_Data.QuadVertexBuffer->SetData(s_Data.QuadVertexBufferBase, dataSize);
//
//            s_Data.QuadShader->Bind();
//            RenderCommand::DrawIndexed(s_Data.QuadVertexArray, s_Data.QuadIndexCount);

        m_stats.QuadCount++;
        m_stats.DrawCalls++;
    }

    void Renderer::DrawCircle()
    {

    }

    void Renderer::DrawString()
    {

    }

    void Renderer::DrawLine()
    {

    }

    void Renderer::DrawTriangle()
    {

    }
}