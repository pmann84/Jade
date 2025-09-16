cmake_minimum_required(VERSION 3.24)

# Project setup
project(Jade)
include(./cmake/project_defaults.cmake)

# Build Profiles

# Configuration - possible options 'opengl', 'vulkan' & 'directx'
set(JADE_BACKEND "opengl")
# Configure what components you want built with the library
# choose from one or more of 'renderer', and 'ui', note that
# the window component is always built since you can' really
# use the others without it!
set(JADE_BUNDLE_RENDERER OFF)

# Build options
option(JADE_BUILD_EXAMPLES "Build example programs" OFF)
#option(JADE_BUILD_TESTS "Build test programs" OFF)

# Other CMake Config
include(./cmake/vulkan.cmake)
include(./cmake/shaders.cmake)
include(./cmake/imgui.cmake)

# Libraries
add_subdirectory(vendor)
add_subdirectory(src)

# Examples
if(JADE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif(JADE_BUILD_EXAMPLES)

enable_testing()

## Tests
#if(JADE_BUILD_TESTS)
#    add_subdirectory(tests)
#endif(JADE_BUILD_TESTS)


