set(SOURCE_FILES main.cpp)

add_executable(runColorFader  ${SOURCE_FILES})

include_directories(librgb)
add_subdirectory(librgb)

target_link_libraries(runColorFader rgb)
