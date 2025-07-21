file(GLOB_RECURSE MYTHFORGER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/**.h
)

add_library(MythForger SHARED ${MYTHFORGER_SRC})

target_include_directories(MythForger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/MythForger/vendor/spdlog/include
)

if(WIN32)
    target_compile_definitions(MythForger PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(MythForger PRIVATE PLATFORM_MAC)
elseif(UNIX)
    target_compile_definitions(MythForger PRIVATE PLATFORM_LINUX)
endif()

target_compile_definitions(MythForger PRIVATE MYTHFORGER_EXPORTS)
target_compile_definitions(MythForger INTERFACE MYTHFORGER_LINKED)