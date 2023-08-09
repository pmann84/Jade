get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME gfxlib_opengl_${PROJECT_ID})

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        Window.cpp Window.hpp
        Events.hpp
        GraphicsContext.cpp GraphicsContext.hpp
        ApplicationBase.hpp
        TimeStepper.hpp)

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