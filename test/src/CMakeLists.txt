include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runColorFaderTests fade_test.cpp rgb_color_test.cpp macros_color_test.h)

target_link_libraries(runColorFaderTests gtest gtest_main)
target_link_libraries(runColorFaderTests rgb)
