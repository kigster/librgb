cmake_minimum_required(VERSION 2.8.7)
project(librgb C CXX)
set(SOURCE_FILES
        arduino-emulation.h
        RGBColor.h
        RGBColor.cpp
        RGBEffect.cpp
        Effect.h
        FadeEffect.h)

add_library(rgb SHARED ${SOURCE_FILES})

install(TARGETS rgb DESTINATION lib)
install(FILES RGBColor.h DESTINATION include)
install(FILES FadeEffect.h DESTINATION include)
