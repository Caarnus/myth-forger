#pragma once

#include <MythForger/Core/Base.h>
#include <MythForger/Logger/Log.h>
#include <filesystem>

#ifdef MF_ENABLE_ASSERTS

    // Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
    // provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
    #define MF_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { MF##type##ERROR(msg, __VA_ARGS__); MF_DEBUGBREAK(); } }
    #define MF_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MF_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
    #define MF_INTERNAL_ASSERT_NO_MSG(type, check) MF_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", MF_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

    #define MF_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
    #define MF_INTERNAL_ASSERT_GET_MACRO(...) MF_EXPAND_MACRO( MF_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MF_INTERNAL_ASSERT_WITH_MSG, MF_INTERNAL_ASSERT_NO_MSG) )

    // Currently accepts at least the condition and one additional parameter (the message) being optional
    #define MF_ASSERT(...) MF_EXPAND_MACRO( MF_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
    #define MF_CORE_ASSERT(...) MF_EXPAND_MACRO( MF_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
    #define MF_ASSERT(...)
    #define MF_CORE_ASSERT(...)
#endif