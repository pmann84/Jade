get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_opengl_${PROJECT_ID})

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        Window.cpp Window.hpp
        Events.hpp
        GraphicsContext.cpp GraphicsContext.hpp
        ApplicationBase.hpp
        TimeStepper.hpp
        ImguiContext.hpp ImguiContext.cpp
        Image.hpp Image.cpp
        ./bindings/imgui_impl_glfw.cpp
        ./bindings/imgui_impl_opengl3.cpp
        ./bindings/imgui_impl_glfw.h
        ./bindings/imgui_impl_opengl3.h
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glad
    PRIVATE glm
    PRIVATE glfw
    PRIVATE imgui)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${GLAD_INCLUDE_DIRS}
    PUBLIC ${GLM_INCLUDE_DIRS}
    PUBLIC ${GLFW_INCLUDE_DIRS}
    PUBLIC ${IMGUI_INCLUDE_DIRS})