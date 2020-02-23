cmake_minimum_required(VERSION 3.10)

project(rev_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror -Weffc++")
endif()

add_library(rev_engine STATIC gfx/graphics.cpp gfx/tile.cpp gfx/texture.cpp)


