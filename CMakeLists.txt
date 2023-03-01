cmake_minimum_required(VERSION 3.23)

project(programming-game-ai-by-example LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

add_subdirectory(src/common)
add_subdirectory(src/chapter2-state-machines)
add_subdirectory(src/chapter3-steering-behaviors)
add_subdirectory(src/chapter4-simple-soccer)
add_subdirectory(src/chapter5-pathfinder)
# add_subdirectory(src/chapter6_scripting_source)
# add_subdirectory(src/chapter7-to-10_raven)
