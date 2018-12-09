//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Enfleurage {

    class Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return msCoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return msClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> msCoreLogger;
        static std::shared_ptr<spdlog::logger> msClientLogger;
    };
}

// Core log macros
#define LOG_CORE_TRACE(...)    ::Enfleurage::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)     ::Enfleurage::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)     ::Enfleurage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)    ::Enfleurage::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...)    ::Enfleurage::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)	       ::Enfleurage::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)	       ::Enfleurage::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)	       ::Enfleurage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)	       ::Enfleurage::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)	       ::Enfleurage::Log::GetClientLogger()->fatal(__VA_ARGS__)