get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME gfxlib_${PROJECT_ID})


add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE Window.cpp Window.hpp IndexBuffer.cpp IndexBuffer.hpp VertexBuffer.cpp VertexBuffer.hpp BufferLayout.cpp BufferLayout.hpp ShaderCommon.hpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE glad
        PRIVATE glfw)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${GLAD_INCLUDE_DIRS}
        PUBLIC ${GLFW_INCLUDE_DIRS})

#target_sources(${FRAMEWORK_PROJECT_NAME}
#        PRIVATE application.cpp image.cpp
#        ../bindings/imgui_impl_glfw.cpp
#        ../bindings/imgui_impl_opengl3.cpp
#        PUBLIC application.hpp logging.hpp image.hpp timer.hpp
#        ../bindings/imgui_impl_glfw.h
#        ../bindings/imgui_impl_opengl3.h)
#

#        PUBLIC spdlog::spdlog
#        PRIVATE glm

#        PRIVATE glfw
#        PRIVATE imgui
#)

#message("GLM INC ${GLM_INCLUDE_DIRS}")


#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
#        PUBLIC ${SPDLOG_INCLUDE_DIRS}
#        PUBLIC ${GLFW_INCLUDE_DIRS}

#        PUBLIC ${GLM_INCLUDE_DIRS}
#        PUBLIC ${IMGUI_INCLUDE_DIRS}
#)