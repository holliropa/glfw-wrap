#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class MouseButtonAction : int {
#ifdef GLFW_PRESS
            Press = GLFW_PRESS,
#endif
#ifdef GLFW_RELEASE
            Release = GLFW_RELEASE,
#endif
        };
    };

    using namespace enums;
}