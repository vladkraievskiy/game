#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    auto window = glfwCreateWindow(100, 100, "temp", nullptr, nullptr);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    return 0;
}