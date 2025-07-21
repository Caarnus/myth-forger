add_executable(SandboxApp SandboxApp.cpp)

target_link_libraries(SandboxApp PRIVATE MythForger)

target_include_directories(SandboxApp PRIVATE
        ${CMAKE_SOURCE_DIR}/MythForger/include
        ${CMAKE_SOURCE_DIR}/MythForger/vendor/spdlog/include
)

add_custom_command(TARGET SandboxApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MythForger>
        $<TARGET_FILE_DIR:SandboxApp>
)