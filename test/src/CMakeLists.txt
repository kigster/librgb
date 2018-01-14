include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src/librgb)

add_executable(runTests FadeEffect_test.cpp RGBColor_test.cpp test_macros.h)

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests rgb)
