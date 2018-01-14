set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(PROJECT_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(CMAKE_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SOURCE_FILES main.cpp)

add_executable(runColorFader  ${SOURCE_FILES})

include_directories(librgb)
add_subdirectory(librgb)

target_link_libraries(runColorFader rgb)
