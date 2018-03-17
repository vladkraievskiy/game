find_package(OpenGL)

add_executable(game main.cpp)

target_include_directories(
        game
        PRIVATE
        ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(
        game
        external_libraries
        ${OPENGL_LIBRARIES}
)