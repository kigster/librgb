include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src/librgb)

add_executable(runTests fade_test.cpp rgb_color_test.cpp macros_color_test.h)

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests rgb)
