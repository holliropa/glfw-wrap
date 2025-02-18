#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class ContextCreationApi {
            Native = GLFW_NATIVE_CONTEXT_API,
            EGL = GLFW_EGL_CONTEXT_API,
            OSMesa = GLFW_OSMESA_CONTEXT_API
        };
    }

    using namespace enums;
}