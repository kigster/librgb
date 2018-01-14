set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(ColorFaderTest CXX)

include_directories(../src/librgb)

add_subdirectory(lib/googletest)
add_subdirectory(src)
