project(glad)

set(SOURCES src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

add_library(
        glad
        ${SOURCES}
)

target_include_directories(glad PUBLIC include)