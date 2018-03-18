#pragma once

#ifdef _WIN32
#define APIENTRY __stdcall
#endif

#include <glad/glad.h>

namespace gl_wrapper {
    bool init(GLADloadproc process);
}