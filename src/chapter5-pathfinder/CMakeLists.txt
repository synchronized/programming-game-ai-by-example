

file(GLOB resource "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(target_name pathfind)

add_executable(${target_name})
target_include_directories(${target_name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(${target_name} PRIVATE ${resource})
target_link_libraries(${target_name} PRIVATE common comctl32.lib)

set(assist icon1.ico no_obstacles_source_target_close.map test_with_walls.map toolbar.aps toolbar.rc toolbar1.bmp)
file(COPY ${assist} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
