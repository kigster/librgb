cmake_minimum_required(VERSION 3.4)
project(librgb C CXX)
set(SOURCE_FILES
        arduino-emulation.h
        RGBColor.h
        RGBColor.cpp
        RGBPixel.h)

add_library(rgb SHARED ${SOURCE_FILES})

install(TARGETS rgb DESTINATION lib)
install(FILES RGBColor.h DESTINATION include)
install(FILES RGBPixel.h DESTINATION include)
