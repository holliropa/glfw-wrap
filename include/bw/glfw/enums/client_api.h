#pragma once

#include "../config.h"

namespace GLFWWRAP_NAMESPACE {
    namespace enums {
        enum class ClientApi {
            OpenGL = GLFW_OPENGL_API,
            OpenGLES = GLFW_OPENGL_ES_API,
            NoApi = GLFW_NO_API
        };
    }

    using namespace enums;
}