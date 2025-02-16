#pragma once

#include "config.h"
#include "window.h"
#include "context.h"

namespace GLFWWRAP_NAMESPACE {
    class GLFW {
    private:
        bool init_;

        explicit GLFW(bool init)
                : init_(init) {}

    public:
        ~GLFW() {
            glfwTerminate();
        }

        [[nodiscard]] bool isInitialized() const {
            return init_;
        }

        [[nodiscard]] friend GLFW init() {
            return GLFW(glfwInit());
        }
    };

    [[nodiscard]] inline GLFW init();

    [[nodiscard]] inline double getTime()
    {
        return glfwGetTime();
    }
}