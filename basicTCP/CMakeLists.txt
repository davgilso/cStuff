cmake_minimum_required (VERSION 3.5)

project(basicTCP)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set (source_dir "${PROJECT_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})



# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(basicTCPClient ${PROJECT_SOURCE_DIR}/client.c)
add_executable(basicTCPServer ${PROJECT_SOURCE_DIR}/server.c)
