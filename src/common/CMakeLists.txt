
add_library(common OBJECT)

file(GLOB resource "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp")

target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(common PRIVATE ${resource})
