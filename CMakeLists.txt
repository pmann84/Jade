cmake_minimum_required(VERSION 3.24)

# Project setup
project(gfxlib)
include(./cmake/project_defaults.cmake)

# Build Profiles

# Configuration - possible options 'opengl', 'vulkan' & 'directx'
set(GFXLIB_BACKEND "opengl")
# Configure what components you want built with the library
# choose from one or more of 'renderer', and 'ui', note that
# the window component is always built since you can' really
# use the others without it!
set(GFXLIB_BUNDLE_RENDERER FALSE)

# Other CMake Config
include(./cmake/vulkan.cmake)
include(./cmake/shaders.cmake)
include(./cmake/imgui.cmake)

# Libraries
add_subdirectory(vendor)
add_subdirectory(src)

# Examples
add_subdirectory(examples)