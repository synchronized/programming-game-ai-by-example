
set(target_name "common")
file(GLOB resource "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp")

add_library(${target_name} STATIC)
target_include_directories(${target_name} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(${target_name} PRIVATE ${resource})
target_link_libraries(${target_name} winmm.lib)
