#pragma once

#include <chrono>

// wrap chrono stuff for easy access to data
// I expect this file to be changed a lot

namespace Lofty
{
    class Duration
    {
    public:
        Duration() {}
        Duration(std::chrono::duration<float, std::milli> dur) : m_Duration(dur) {}

        float FloatMilliseconds() { return m_Duration.count(); }
        long long LLNanoseconds() { return std::chrono::duration_cast<std::chrono::nanoseconds>(m_Duration).count(); }
        long long LLMilliseconds() { return std::chrono::duration_cast<std::chrono::milliseconds>(m_Duration).count(); }

    private:
        std::chrono::duration<float, std::milli> m_Duration;
    };

    class TimePoint
    {
    public:
        TimePoint() {}
        TimePoint(std::chrono::time_point<std::chrono::steady_clock> time) : m_Time(time) {}

        Duration operator-(const TimePoint& other)
        {
            return Duration(this->m_Time - other.m_Time);
        }

    private:
        std::chrono::time_point<std::chrono::steady_clock> m_Time;
    };

    class Time
    {
    public:
        Time() {}
        TimePoint Now() { return TimePoint(m_Timer.now()); }

    private:
        std::chrono::high_resolution_clock m_Timer;
    };
    
}

