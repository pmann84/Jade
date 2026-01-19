get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_opengl_examples_${PROJECT_ID})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        PRIVATE jade_opengl_window
        PRIVATE jade_opengl_renderer)

copy_shaders(${PROJECT_NAME})