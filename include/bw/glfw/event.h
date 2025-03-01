#pragma once

#include <functional>

namespace glfw {
    template <typename... Args>
    class Event {
        std::function<void(Args...)> _handler;

    public:
        template <typename Callback>
        void set(Callback&& callback_) {
            _handler = std::forward<Callback>(callback_);
        }

        void operator()(Args... args_) {
            if (_handler) {
                _handler(args_...);
            }
        }
    };
}
