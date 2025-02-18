#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class ModifierKeyBit : int {
#ifdef GLFW_MOD_SHIFT
            Shift = GLFW_MOD_SHIFT,
#endif
#ifdef GLFW_MOD_CONTROL
            Control = GLFW_MOD_CONTROL,
#endif
#ifdef GLFW_MOD_ALT
            Alt = GLFW_MOD_ALT,
#endif
#ifdef GLFW_MOD_SUPER
            Super = GLFW_MOD_SUPER,
#endif
#ifdef GLFW_MOD_CAPS_LOCK
            CapsLock = GLFW_MOD_CAPS_LOCK,
#endif
#ifdef GLFW_MOD_NUM_LOCK
            NumLock = GLFW_MOD_NUM_LOCK,
#endif
        };
    }

    using namespace enums;
}
