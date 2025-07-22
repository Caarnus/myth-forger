set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger/Log.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mfpch.cpp
)

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Base.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Assert.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/KeyCodes.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/MouseCodes.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/EntryPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Events/Event.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Events/KeyEvent.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Events/MouseEvent.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Events/ApplicationEvent.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Logger/Log.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Debug/Instrumentor.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Util/PlatformDetection.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mfpch.h
)

add_library(MythForger SHARED ${SOURCES})
target_sources(MythForger PRIVATE ${HEADERS})

target_include_directories(MythForger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

target_precompile_headers(MythForger PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/mfpch.h)

target_compile_definitions(MythForger PRIVATE MYTHFORGER_EXPORTS)
target_compile_definitions(MythForger INTERFACE MYTHFORGER_LINKED)