get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_${PROJECT_ID})

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME}
    INTERFACE events.hpp window.hpp application.hpp
)

# Exports all the include directories needed for this library
target_include_directories(${PROJECT_NAME}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    INTERFACE ${GLM_INCLUDE_DIRS}
)