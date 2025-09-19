get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_opengl_${PROJECT_ID})

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
        PRIVATE
        opengl_application.hpp
        opengl_application.cpp
        #        ./bindings/imgui_impl_glfw.cpp
        #        ./bindings/imgui_impl_opengl3.cpp
        #        ./bindings/imgui_impl_glfw.h
        #        ./bindings/imgui_impl_opengl3.h
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE jade_common
        PRIVATE jade_opengl_window
        PRIVATE glfw
)
#    PRIVATE glad
#    PRIVATE glm
#
#    PRIVATE imgui)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${JADE_OPENGL_WINDOW_INCLUDE_DIRS}
        PUBLIC ${GLFW_INCLUDE_DIRS}
)
#    PUBLIC ${GLAD_INCLUDE_DIRS}
#    PUBLIC ${GLM_INCLUDE_DIRS}
#    PUBLIC ${IMGUI_INCLUDE_DIRS})