#pragma once

#include "MythForger/Util/PlatformDetection.h"

#ifdef MF_PLATFORM_WINDOWS
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "MythForger/Core/Base.h"

#include "MythForger/Logger/Log.h"

#include "MythForger/Debug/Instrumentor.h"

#ifdef MF_PLATFORM_WINDOWS
    #include <Windows.h>
#endif