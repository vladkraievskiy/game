find_package(bullet)

if ((NOT BULLET_INCLUDE_DIR) OR (NOT EXISTS ${BULLET_INCLUDE_DIR}))
    message(FATAL_ERROR "Please install bullet. https://github.com/bulletphysics/bullet3/releases")
endif((NOT BULLET_INCLUDE_DIR) OR (NOT EXISTS ${BULLET_INCLUDE_DIR}))

add_library(external_libraries INTERFACE)

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glm/CMakeLists.txt")
    message("Not found glm sources. Clonning glm from git repository.")

    execute_process(
            COMMAND git submodule update --init --checkout -- glm
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glm/CMakeLists.txt")

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glfw/CMakeLists.txt")
    message("Not found glfw sources. Clonning glfw from git repository.")

    execute_process(
            COMMAND git submodule update --init --checkout -- glfw
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/glfw/CMakeLists.txt")

add_subdirectory(glfw EXCLUDE_FROM_ALL)
set(LIBRARIES ${LIBRARIES} glfw)

add_subdirectory(gl EXCLUDE_FROM_ALL)
set(LIBRARIES ${LIBRARIES} gl_wrapper)

add_subdirectory(stb_image EXCLUDE_FROM_ALL)
set(LIBRARIES ${LIBRARIES} stb_image)

target_include_directories(
        external_libraries
        INTERFACE
        glm
        ${BULLET_INCLUDE_DIR}
)

target_link_libraries(external_libraries INTERFACE ${LIBRARIES} ${BULLET_LIBRARIES})