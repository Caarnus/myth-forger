#pragma once

#if defined(PLATFORM_WINDOWS)
    #define MYTH_PLATFORM_NAME "Windows"
#elif defined(PLATFORM_LINUX)
    #define MYTH_PLATFORM_NAME "Linux"
#elif defined(PLATFORM_MAC)
    #define MYTH_PLATFORM_NAME "macOS"
#else
    #define MYTH_PLATFORM_NAME "Unknown"
#endif