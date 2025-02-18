#pragma once

#include "config.h"
#include "window.h"
#include "context.h"
#include "hints.h"

namespace GLFWWRAP_NAMESPACE {
    [[nodiscard]] inline bool init() {
        return glfwInit() == GLFW_TRUE;
    }

    inline void terminate() {
        glfwTerminate();
    }

    [[nodiscard]] inline double getTime() {
        return glfwGetTime();
    }
}