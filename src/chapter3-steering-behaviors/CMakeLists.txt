

file(GLOB resource "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(target_name steering-behaviors)

add_executable(${target_name})
target_include_directories(${target_name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(${target_name} PRIVATE ${resource})
target_link_libraries(${target_name} PRIVATE common)

file(COPY params.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
