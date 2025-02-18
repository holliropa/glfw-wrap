#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class CursorMode : int {
            Normal = GLFW_CURSOR_NORMAL,
            Disabled = GLFW_CURSOR_DISABLED,
            Hidden = GLFW_CURSOR_HIDDEN
        };
    }

    using namespace enums;
}