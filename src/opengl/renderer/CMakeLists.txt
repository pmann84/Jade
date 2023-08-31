get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME gfxlib_opengl_${PROJECT_ID})

add_library(${PROJECT_NAME})

add_shader(${PROJECT_NAME} shaders/quad.vert)
add_shader(${PROJECT_NAME} shaders/quad.frag)

target_sources(${PROJECT_NAME}
        PRIVATE VertexArray.cpp VertexArray.hpp
        IndexBuffer.cpp IndexBuffer.hpp
        VertexBuffer.cpp VertexBuffer.hpp
        BufferLayout.cpp BufferLayout.hpp
        Shader.cpp Shader.hpp
        RenderApi.cpp RenderApi.hpp
        Renderer.cpp Renderer.hpp
        RendererStatistics.hpp
        Camera.cpp Camera.hpp
        ShaderCommon.hpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE glad
        PRIVATE glm
        PRIVATE glfw)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${GLAD_INCLUDE_DIRS}
        PUBLIC ${GLM_INCLUDE_DIRS}
        PUBLIC ${GLFW_INCLUDE_DIRS})

