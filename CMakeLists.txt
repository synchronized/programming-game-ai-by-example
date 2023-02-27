cmake_minimum_required(VERSION 3.23)

set(toolpath D:/sunday/programs/scoop/apps/mingw-winlibs/current)
set(CMAKE_C_COMPILER ${tools}/bin/gcc.exe)
set(CMAKE_CXX_COMPILER ${tools}/bin/g++.exe)

project(programming-game-ai-by-example LANGUAGES C CXX)

message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

add_subdirectory(src/common)
add_subdirectory(src/chapter2-state-machines)
add_subdirectory(src/chapter3-steering-behaviors)
# add_subdirectory(src/chapter4-simple-soccer)
# add_subdirectory(src/chapter5-pathfinder)
# add_subdirectory(src/chapter6_scripting_source)
# add_subdirectory(src/chapter7-to-10_raven)
