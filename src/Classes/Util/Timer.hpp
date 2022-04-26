#pragma once
#include <chrono>

namespace Util
{
    struct Timer
    {
    private:
        static std::chrono::steady_clock::time_point _begin;
        static std::chrono::steady_clock::time_point _end;

    public:
        static void begin()
        {
            _begin = std::chrono::steady_clock::now();
        }
        static void end()
        {
            _end = std::chrono::steady_clock::now();
        }
        static int elapsedTime()
        {
            return std::chrono::duration_cast<std::chrono::microseconds>(_end - _begin).count();
        }
    };
}
