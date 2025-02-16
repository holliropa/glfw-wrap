#pragma once

#include "config.h"
#include "window.h"

namespace GLFWWRAP_NAMESPACE {
    inline void makeContextCurrent(const Window &window) {
        glfwMakeContextCurrent(static_cast<GLFWwindow *>(window));
    }
}