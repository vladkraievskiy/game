#include <gl_wrapper/gl.h>

namespace gl_wrapper {
    bool init(GLADloadproc process) {
        return static_cast<bool>(gladLoadGLLoader(process));
    }
}