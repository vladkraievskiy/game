project(gl_wrapper)

add_library(
        gl_wrapper
        src/gl.cpp
        include/gl_wrapper/gl.h
)

add_subdirectory(glad EXCLUDE_FROM_ALL)

set(LIBRARIES ${LIBRARIES} glad)

target_include_directories(
        gl_wrapper
        PUBLIC
        glad/include
        include
)

find_package(OpenGL)
target_include_directories(gl_wrapper PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(gl_wrapper ${LIBRARIES} ${OPENGL_LIBRARIES})