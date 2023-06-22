cmake_minimum_required(VERSION 3.24)

# Project setup
project(gfxlib)
include(./cmake/project_defaults.cmake)

# Build Profiles

# Configuration - possible options 'opengl', 'vulkan' & 'directx'
set(GFXLIB_BUILD "opengl")

# Libraries
add_subdirectory(vendor)
add_subdirectory(src)

# Examples
add_subdirectory(examples)