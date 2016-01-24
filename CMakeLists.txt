cmake_minimum_required(VERSION 2.8.7)
project(ColorFader C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(ColorFader_run  ${SOURCE_FILES})

include_directories(librgb)
add_subdirectory(librgb)
add_subdirectory(test)

target_link_libraries(ColorFader_run rgb)
