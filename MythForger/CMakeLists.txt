set(SOURCES
    src/MythForger/Core/Application.cpp
    src/MythForger/Logger/Log.cpp
    src/mfpch.cpp
        src/Platform/Windows/WindowsWindow.cpp
        src/Platform/Windows/WindowsWindow.h
)

set(HEADERS
    src/MythForger/Core/Application.h
    src/MythForger/Core/Base.h
    src/MythForger/Core/Assert.h
    src/MythForger/Core/KeyCodes.h
    src/MythForger/Core/MouseCodes.h
    src/MythForger/Core/EntryPoint.h
    src/MythForger/Core/Window.h
    src/MythForger/Events/Event.h
    src/MythForger/Events/KeyEvent.h
    src/MythForger/Events/MouseEvent.h
    src/MythForger/Events/ApplicationEvent.h
    src/MythForger/Logger/Log.h
    src/MythForger/Debug/Instrumentor.h
    src/MythForger/Util/PlatformDetection.h
    src/mfpch.h
)

# Add vendor libraries
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/spdlog)

add_library(MythForger SHARED ${SOURCES})
target_sources(MythForger PRIVATE ${HEADERS})

target_include_directories(MythForger PUBLIC
    src
    include
    vendor/glfw/include/GLFW
    vendor/glm/glm
    vendor/spdlog/include
)

# Link to static vendor libs
target_link_libraries(MythForger PRIVATE glfw glm spdlog)

target_precompile_headers(MythForger PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/mfpch.h)

target_compile_definitions(MythForger PRIVATE MYTHFORGER_EXPORTS)
target_compile_definitions(MythForger INTERFACE MYTHFORGER_LINKED)