set(CMAKE_BINARY_DIR ${CMAKE_ROOT}/build)
set(PROJECT_BINARY_DIR ${CMAKE_ROOT}/build)

set(SOURCE_FILES
        arduino-emulation.h
        RGBColor.h
        RGBColor.cpp
        Effect.h
        FadeEffect.h)

add_library(rgb SHARED ${SOURCE_FILES})

install(TARGETS rgb DESTINATION lib)
install(FILES RGBColor.h DESTINATION include)
install(FILES FadeEffect.h DESTINATION include)
