file(GLOB_RECURSE MYTHFORGER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/**.h
)

add_library(MythForger SHARED ${MYTHFORGER_SRC}
        src/Core/Base.h
        src/Core/Assert.h)

target_include_directories(MythForger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/MythForger/vendor/glm/glm
    ${CMAKE_SOURCE_DIR}/MythForger/vendor/spdlog/include
)

target_compile_definitions(MythForger PRIVATE MYTHFORGER_EXPORTS)
target_compile_definitions(MythForger INTERFACE MYTHFORGER_LINKED)