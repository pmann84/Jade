#include "RenderApi.hpp"

#include "glad/glad.h"
#include <iostream>

namespace gfxlib
{
    void RenderApi::initialise()
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
    }

    void RenderApi::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void RenderApi::setClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void RenderApi::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RenderApi::drawIndexed(const std::shared_ptr<VertexArray> &vertexArray, uint32_t indexCount)
    {
        vertexArray->bind();
        uint32_t count = indexCount ? indexCount : vertexArray->indexBuffer()->count();
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
    }

    void RenderApi::drawLines(const std::shared_ptr<VertexArray> &vertexArray, uint32_t vertexCount)
    {
        vertexArray->bind();
        glDrawArrays(GL_LINES, 0, vertexCount);
    }

    void RenderApi::setLineWidth(float width)
    {
        glLineWidth(width);
    }
}

//void OpenGLMessageCallback(
//        unsigned source,
//        unsigned type,
//        unsigned id,
//        unsigned severity,
//        int length,
//        const char* message,
//        const void* userParam)
//{
//    switch (severity)
//    {
//        case GL_DEBUG_SEVERITY_HIGH:         HZ_CORE_CRITICAL(message); return;
//        case GL_DEBUG_SEVERITY_MEDIUM:       HZ_CORE_ERROR(message); return;
//        case GL_DEBUG_SEVERITY_LOW:          HZ_CORE_WARN(message); return;
//        case GL_DEBUG_SEVERITY_NOTIFICATION: HZ_CORE_TRACE(message); return;
//    }
//
//    HZ_CORE_ASSERT(false, "Unknown severity level!");
//}
//
//void OpenGLRendererAPI::Init()
//{
//    HZ_PROFILE_FUNCTION();
//
//#ifdef HZ_DEBUG
//    glEnable(GL_DEBUG_OUTPUT);
//		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
//		glDebugMessageCallback(OpenGLMessageCallback, nullptr);
//
//		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
//#endif
//}
