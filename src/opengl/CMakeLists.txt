message(STATUS "Adding OPENGL framework library.")
add_subdirectory(window)
add_subdirectory(application)

#if (JADE_BUNDLE_RENDERER)
#    message(STATUS "Adding OPENGL rendering library.")
#    add_subdirectory(renderer)
#endif()



#get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#set(PROJECT_NAME JADE_${PROJECT_ID})
#
#add_library(${PROJECT_NAME})
#
#add_shader(${PROJECT_NAME} shaders/quad.vert)
#add_shader(${PROJECT_NAME} shaders/quad.frag)
#
#target_sources(${PROJECT_NAME}
#        PRIVATE window/Window.cpp window/Window.hpp
#        rendering/VertexArray.cpp rendering/VertexArray.hpp
#        rendering/IndexBuffer.cpp rendering/IndexBuffer.hpp
#        rendering/VertexBuffer.cpp rendering/VertexBuffer.hpp
#        rendering/BufferLayout.cpp rendering/BufferLayout.hpp
#        rendering/Shader.cpp rendering/Shader.hpp
#        rendering/RenderApi.cpp rendering/RenderApi.hpp
#        rendering/Renderer.cpp rendering/Renderer.hpp
#        rendering/GraphicsContext.cpp rendering/GraphicsContext.hpp
#        rendering/Camera.cpp rendering/Camera.hpp
#        rendering/ShaderCommon.hpp
#        rendering/Events.hpp)
#
#target_link_libraries(${PROJECT_NAME}
#        PRIVATE glad
#        PRIVATE glm
#        PRIVATE glfw)
#
## Exports all the include directories needed for this library
#target_include_directories(${PROJECT_NAME}
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
#        PUBLIC ${GLAD_INCLUDE_DIRS}
#        PUBLIC ${GLM_INCLUDE_DIRS}
#        PUBLIC ${GLFW_INCLUDE_DIRS})

#target_sources(${FRAMEWORK_PROJECT_NAME}
#        PRIVATE application.cpp image.cpp
#        ../bindings/imgui_impl_glfw.cpp
#        ../bindings/imgui_impl_opengl3.cpp
#        PUBLIC application.hpp logging.hpp image.hpp timer.hpp
#        ../bindings/imgui_impl_glfw.h
#        ../bindings/imgui_impl_opengl3.h)
#        PUBLIC spdlog::spdlog
#        PRIVATE imgui
#)
#        PUBLIC ${SPDLOG_INCLUDE_DIRS}
#        PUBLIC ${IMGUI_INCLUDE_DIRS}
#)