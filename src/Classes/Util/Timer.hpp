#pragma once
#include <chrono>

namespace Util
{
    struct Timer
    {
        static std::chrono::steady_clock::time_point _begin;
        static std::chrono::steady_clock::time_point _end;

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

    std::chrono::steady_clock::time_point Timer::_begin;
    std::chrono::steady_clock::time_point Timer::_end;
}
