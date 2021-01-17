#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Lofty
{
    class Logger
    {
    public:
        static void Init();
        
        inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
    
    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#ifdef _DEBUG
// logging defines
#define LOG_TRACE(...)   ::Lofty::Logger::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)    ::Lofty::Logger::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)    ::Lofty::Logger::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)   ::Lofty::Logger::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)   ::Lofty::Logger::GetLogger()->fatal(__VA_ARGS__)
#else
#define LOG_TRACE(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_FATAL(...)
#endif // _DEBUG

