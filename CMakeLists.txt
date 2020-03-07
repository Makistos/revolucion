cmake_minimum_required(VERSION 3.10)

project(revolucion VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror -Weffc++")
endif()

add_executable(revolucion main.cpp eventhandler.cpp)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

add_library(rev_engine STATIC IMPORTED)
set_target_properties(rev_engine PROPERTIES
	IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/engine/librev_engine.a")
add_library(tileson STATIC IMPORTED)
set_target_properties(tileson PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/engine/tileson/libtileson.a")

include_directories(${SDL2_INCLUDE_DIRS}
                    ${SDL2_IMAGE_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/engine
                    ${CMAKE_CURRENT_SOURCE_DIR}/engine/gfx/inc
                    ${CMAKE_CURRENT_SOURCE_DIR}/engine/tileson/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/engine/tileson/external_libs
                    )

target_link_libraries(revolucion ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} rev_engine tileson)
