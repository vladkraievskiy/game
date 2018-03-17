project(stb_image)

set(SOURCES src/stb_image.cpp include/stb_image.h)

add_library(
        stb_image
        ${SOURCES}
)

target_include_directories(stb_image PUBLIC include)