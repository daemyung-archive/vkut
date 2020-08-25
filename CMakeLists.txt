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

#------------------------------------------------------------------------------

add_library(vkut
  STATIC
    include/vkut.h
    source/vkut.cpp
)

#------------------------------------------------------------------------------

target_include_directories(vkut
  PUBLIC
    include/
)

#------------------------------------------------------------------------------

target_link_libraries(vkut
  PUBLIC
    Vulkan::Vulkan
)

#------------------------------------------------------------------------------
