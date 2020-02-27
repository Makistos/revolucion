cmake_minimum_required(VERSION 3.10)

project(rev_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror -Weffc++")
endif()

add_library(rev_engine STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/gfx/src/graphics.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gfx/src/tileset.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gfx/src/tile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gfx/src/texture.cpp)

include_directories(rev_engine
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gfx/inc>
    PRIVATE
        ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/tileson/src
        ${CMAKE_CURRENT_SOURCE_DIR}/tileson/external_libs
    )