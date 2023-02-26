
add_executable(westworld1)

file(GLOB resource "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_include_directories(westworld1 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(westworld1 PRIVATE ${resource})
target_link_libraries(westworld1 PRIVATE common)
