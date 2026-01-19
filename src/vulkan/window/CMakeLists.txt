get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_vulkan_${PROJECT_ID})

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
        PRIVATE
        vulkan_window.hpp
        vulkan_window.cpp
        #        ./bindings/imgui_impl_glfw.cpp
        #        ./bindings/imgui_impl_opengl3.cpp
        #        ./bindings/imgui_impl_glfw.h
        #        ./bindings/imgui_impl_opengl3.h
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE jade_common
        PRIVATE glfw
        PRIVATE ${VULKAN_LIB_LIST}
)

#    PRIVATE glad
#    PRIVATE glm
#
#    PRIVATE imgui)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${GLFW_INCLUDE_DIRS}
)

set(JADE_VULKAN_WINDOW_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
#    PUBLIC ${GLAD_INCLUDE_DIRS}
#    PUBLIC ${GLM_INCLUDE_DIRS}
#    PUBLIC ${IMGUI_INCLUDE_DIRS})