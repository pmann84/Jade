set(imgui_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)

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

if(JADE_BACKEND STREQUAL "opengl")
    set(OPENGL_COPY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/opengl/window/bindings)
    message("Copying files to ${OPENGL_COPY_DIR}")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp ${OPENGL_COPY_DIR}/imgui_impl_glfw.cpp COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.h ${OPENGL_COPY_DIR}/imgui_impl_glfw.h COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp ${OPENGL_COPY_DIR}/imgui_impl_opengl3.cpp COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.h ${OPENGL_COPY_DIR}/imgui_impl_opengl3.h COPYONLY)
endif()