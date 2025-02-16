#pragma once

#include "config.h"
#include "event.h"

namespace GLFWWRAP_NAMESPACE {
    class Window {
    private:
        GLFWwindow *window;

        static Window &_getWrapperFromHandle(GLFWwindow *handle_) {
            return *static_cast<Window *>(glfwGetWindowUserPointer(handle_));
        }

        static void _framebufferSizeCallback(GLFWwindow *window_, int width_, int height_) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.framebufferSizeEvent(wrapper, width_, height_);
        }

    public:
        Event<Window &, int, int> framebufferSizeEvent;

        Window(int width,
               int height,
               const char *title,
               GLFWmonitor *monitor = nullptr,
               GLFWwindow *share = nullptr) {
            window = glfwCreateWindow(width, height, title, monitor, share);

            glfwSetWindowUserPointer(window, this);

            glfwSetFramebufferSizeCallback(window, _framebufferSizeCallback);
        }

        ~Window() {
            glfwDestroyWindow(window);
        }

        [[nodiscard]] bool isValid() const {
            return window;
        }

        [[nodiscard]] bool shouldClose() const {
            return glfwWindowShouldClose(window);
        }

        void setShouldClose(bool value) {
            glfwSetWindowShouldClose(window, value);
        }

        void swapBuffers() {
            glfwSwapBuffers(window);
        }

        explicit operator GLFWwindow *() const {
            return window;
        }
    };
}