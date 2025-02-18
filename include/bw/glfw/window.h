#pragma once

#include "config.h"
#include "event.h"
#include "enums/key_code.h"
#include "enums/key_action.h"
#include "enums/modifier_key_bit.h"
#include "enums/mouse_button.h"
#include "enums/mouse_button_action.h"
#include "enums/cursor_mode.h"

namespace GLFWWRAP_NAMESPACE {
    class Window {
    private:
        GLFWwindow *window;

        static Window &_getWrapperFromHandle(GLFWwindow *handle_) {
            return *static_cast<Window *>(glfwGetWindowUserPointer(handle_));
        }

        static void _framebufferSizeCallback(GLFWwindow *window_, int width_, int height_) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.framebufferSizeEvent(width_, height_);
        }

        static void _keyCallback(GLFWwindow *window_, int key, int scancode, int action, int mods) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.keyEvent(static_cast<KeyCode>(key),
                             scancode,
                             static_cast<KeyAction>(action),
                             static_cast<ModifierKeyBit>(mods));
        }

        static void _cursorPosCallback(GLFWwindow *window_, double x, double y) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.cursorPosEvent(x, y);
        }

        static void _mouseButtonCallback(GLFWwindow *window_, int button, int action, int mods) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.mouseButtonEvent(static_cast<MouseButton>(button),
                                     static_cast<MouseButtonAction>(action),
                                     static_cast<ModifierKeyBit>(mods));
        }

        static void _cursorEnterCallback(GLFWwindow *window_, int enter) {
            Window &wrapper = _getWrapperFromHandle(window_);
            wrapper.cursorEnterEvent(static_cast<bool>(enter));
        }

    public:
        Event<int, int> framebufferSizeEvent;
        Event<KeyCode, int, KeyAction, ModifierKeyBit> keyEvent;
        Event<double, double> cursorPosEvent;
        Event<MouseButton, MouseButtonAction, ModifierKeyBit> mouseButtonEvent;
        Event<bool> cursorEnterEvent;

        Window(int width,
               int height,
               const char *title,
               GLFWmonitor *monitor = nullptr,
               GLFWwindow *share = nullptr) {
            window = glfwCreateWindow(width, height, title, monitor, share);

            glfwSetWindowUserPointer(window, this);

            glfwSetFramebufferSizeCallback(window, _framebufferSizeCallback);
            glfwSetKeyCallback(window, _keyCallback);
            glfwSetCursorPosCallback(window, _cursorPosCallback);
            glfwSetMouseButtonCallback(window, _mouseButtonCallback);
            glfwSetCursorEnterCallback(window, _cursorEnterCallback);
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

        void setShouldClose(bool value) const {
            glfwSetWindowShouldClose(window, value);
        }

        void swapBuffers() const {
            glfwSwapBuffers(window);
        }

        void setTitle(const char* title_) const
        {
            glfwSetWindowTitle(window, title_);
        }

        void setCursorMode(CursorMode mode) const {
            glfwSetInputMode(window, GLFW_CURSOR, static_cast<int>(mode));
        }

        void getCursorPosition(double *x, double *y) const {
            glfwGetCursorPos(window, x, y);
        }

        void setCursorPosition(double x, double y) const {
            glfwSetCursorPos(window, x, y);
        }

        explicit operator GLFWwindow *() const {
            return window;
        }
    };
}