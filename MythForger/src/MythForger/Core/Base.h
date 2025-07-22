#pragma once

#include <MythForger/Util/PlatformDetection.h>

#include <memory>

#if defined(MF_DEBUG_BUILD) || defined(MF_RELEASE_BUILD)
        #define MF_ENABLE_ASSERTS
#endif

#ifdef MF_DEBUG
        #if defined(MF_PLATFORM_WINDOWS)
                #define MF_DEBUGBREAK() _debugbreak()
        #elif defined(MF_PLATFORM_LINUX)
                #include <signal.h>
                #define MF_DEBUGBREAK() raise(SIGTRAP)
        #else
                #error "Platform doesn't support debugbreak yet!"
        #endif
        #define MF_ENABLE_ASSERTS
#else
        #define MF_DEBUGBREAK()
#endif

#define MF_EXPAND_MACRO(x) x
#define MF_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define MF_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace MythForger {
        template<typename T>
        using Scope = std::unique_ptr<T>;
        template<typename T, typename ... Args>
        constexpr Scope<T> CreateScope(Args&& ... args)
        {
                return std::make_unique<T>(std::forward<Args>(args)...);
        }

        template<typename T>
        using Ref = std::shared_ptr<T>;
        template<typename T, typename ... Args>
        constexpr Ref<T> CreateRef(Args&& ... args)
        {
                return std::make_shared<T>(std::forward<Args>(args)...);
        }
}

#include <MythForger/Logger/Log.h>
#include <MythForger/Core/Assert.h>