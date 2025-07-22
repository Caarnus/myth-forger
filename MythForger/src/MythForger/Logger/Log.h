#pragma once

#include <MythForger/Core/Base.h>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace MythForger {

    class Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define MF_CORE_TRACE(...)      ::MythForger::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MF_CORE_DEBUG(...)      ::MythForger::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define MF_CORE_INFO(...)       ::MythForger::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MF_CORE_WARN(...)       ::MythForger::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MF_CORE_ERROR(...)      ::MythForger::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MF_CORE_CRITICAL(...)   ::MythForger::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MF_TRACE(...)           ::MythForger::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MF_DEBUG(...)           ::MythForger::Log::GetClientLogger()->debug(__VA_ARGS__)
#define MF_INFO(...)            ::MythForger::Log::GetClientLogger()->info(__VA_ARGS__)
#define MF_WARN(...)            ::MythForger::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MF_ERROR(...)           ::MythForger::Log::GetClientLogger()->error(__VA_ARGS__)
#define MF_CRITICAL(...)        ::MythForger::Log::GetClientLogger()->critical(__VA_ARGS__)
