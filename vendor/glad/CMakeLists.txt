set(glad_PATH ${CMAKE_SOURCE_DIR}/vendor/glad)

add_library(glad
        ${glad_PATH}/include/glad/glad.h
        ${glad_PATH}/include/KHR/khrplatform.h
        ${glad_PATH}/src/glad.c
        )

set(GLAD_INCLUDE_DIRS ${glad_PATH}/include PARENT_SCOPE)
target_include_directories(glad PUBLIC ${glad_PATH}/include/)