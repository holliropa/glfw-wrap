#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class KeyAction : int {
#ifdef GLFW_PRESS
            Press = GLFW_PRESS,
#endif
#ifdef GLFW_RELEASE
            Release = GLFW_RELEASE,
#endif
#ifdef GLFW_REPEAT
            Repeat = GLFW_REPEAT,
#endif
        };
    };

    using namespace enums;
}