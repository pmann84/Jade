set(imgui_PATH ${CMAKE_SOURCE_DIR}/vendor/imgui)

add_library(imgui
    ${imgui_PATH}/imconfig.h
    ${imgui_PATH}/imgui.h
    ${imgui_PATH}/imgui.cpp
    ${imgui_PATH}/imgui_draw.cpp
    ${imgui_PATH}/imgui_internal.h
    ${imgui_PATH}/imgui_tables.cpp
    ${imgui_PATH}/imgui_demo.cpp
    ${imgui_PATH}/imgui_widgets.cpp
    ${imgui_PATH}/imstb_rectpack.h
    ${imgui_PATH}/imstb_textedit.h
    ${imgui_PATH}/imstb_truetype.h
)

set(IMGUI_INCLUDE_DIRS ${imgui_PATH})
target_include_directories(imgui
    PUBLIC ${imgui_PATH}
    PUBLIC ${imgui_PATH}/backends/)

if(GFXLIB_BACKEND STREQUAL "opengl")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_glfw.cpp COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.h ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_glfw.h COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.h ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_opengl3.h COPYONLY)
endif()