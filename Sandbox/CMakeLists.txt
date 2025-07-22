add_executable(SandboxApp SandboxApp.cpp)

target_link_libraries(SandboxApp PRIVATE MythForger)

add_custom_command(TARGET SandboxApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:MythForger>
        $<TARGET_FILE_DIR:SandboxApp>
)