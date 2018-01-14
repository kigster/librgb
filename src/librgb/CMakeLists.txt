cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(rgb CXX)

set(SOURCE_FILES
        arduino-emulation.h
        RGBColor.h
        RGBColor.cpp
        Effect.h
        FadeEffect.h)

add_library(rgb SHARED ${SOURCE_FILES} )

install(TARGETS rgb DESTINATION lib)
install(FILES RGBColor.h DESTINATION include)
install(FILES FadeEffect.h DESTINATION include)
