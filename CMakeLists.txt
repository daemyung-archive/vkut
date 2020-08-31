#
# This file is part of the "vkut" project
# See "LICENSE" for license information.
#

#------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

#------------------------------------------------------------------------------

project(vkut VERSION 0.1.0)

#------------------------------------------------------------------------------

find_package(Vulkan REQUIRED)
find_package(Threads REQUIRED)
find_package(glslang CONFIG REQUIRED)

#------------------------------------------------------------------------------

add_library(vkut
  STATIC
    include/vkut.h
    include/vkut/core.h
    include/vkut/extension.h
    source/extension.cpp
)

#------------------------------------------------------------------------------

target_include_directories(vkut
  PUBLIC
    include
  PRIVATE
    include/vkut
)

#------------------------------------------------------------------------------

target_link_libraries(vkut
  PUBLIC
    Vulkan::Vulkan
    glslang::glslang
    glslang::SPIRV
    glslang::HLSL
    glslang::OGLCompiler
)

#------------------------------------------------------------------------------

set_target_properties(vkut
  PROPERTIES
    CXX_STANDARD 17
)

#------------------------------------------------------------------------------
